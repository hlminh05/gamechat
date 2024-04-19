#include "gameloop.h"
#include "Object.h"
#include "bkg.h"

bool Gameloop::GameState = false;
int Gameloop::score = 0;
int Gameloop::timer = 0;
int Gameloop::FPS = 120;

int Gameloop::HEIGHT = 512;
int Gameloop::WIDTH = 624;
SDL_Window *Gameloop::window = nullptr;
SDL_Renderer *Gameloop::renderer = nullptr;
SDL_Event Gameloop::event;

std::vector<bkg *> Gameloop::BKG;
std::vector<item *> Gameloop::ITEM;
std::vector<player *> Gameloop::PLAYER;
std::vector<pipe *> Gameloop::PIPE;

SDL_Texture *texScore = nullptr;
SDL_Rect srcScore, destScore;
SDL_Texture *texHScore = nullptr;
SDL_Rect srcHScore, destHScore;

Gameloop::Gameloop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
}

bool Gameloop::GetGameState()
{
    return GameState;
}

void Gameloop::CreateWindow()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy happy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "created!" << std::endl;
            GameState = true;
        }
        else
            std::cout << "not created!" << std::endl;
    }
    else
    {
        std::cout << "window not created!" << std::endl;
    }

    TTF_Init();
    TextureManager::font = TTF_OpenFont("font/font2.ttf", 24);
    TextureManager::color = {0, 0, 0};
}

void Gameloop::addItem(bool t)
{
    item *it;
    if (t)
    {
        it = new item;
        it->SetImage("img/rocket.png");
        it->SetPos(-100, rand() % (400 - it->dest.h));
        it->space = 800;
        it->type = "rocket";
        it->SetScale(0.15);
        it->speed_item = 1;

        it = new item;
        it->SetImage("img/bnn.png");
        it->SetPos(-100, rand() % (400 - it->dest.h));
        it->type = "chuoi";
        it->space = 1800;
        it->val = 3;
        it->SetScale(0.2);
        it->speed_item = 5;

        it = new item;
        it->SetImage("img/special.png");
        it->SetPos(-100, rand() % (400 - it->dest.h));
        it->type = "special";
        it->val = 10;
        it->space = 10000;
        it->SetScale(2);
        it->speed_item = 8;

        it = new item;
        it->SetImage("img/bomb.png");
        it->SetPos(-100, rand() % (400 - it->dest.h));
        it->type = "bom";
        it->space = 800;
        it->SetScale(1);
        it->speed_item = 2;
    }
    it = new item;
    it->SetImage("img/apple.png");
    it->type = "tao";
    it->space = 800;
    it->val = 5;
    it->SetPos(-100, rand() % (400 - it->dest.h));
    it->SetScale(0.8);
    it->speed_item = 4;

    it = new item;
    it->SetImage("img/luu.png");
    it->SetPos(-100, rand() % (400 - it->dest.h));
    it->type = "luu";
    it->val = 3;
    it->space = 800;
    it->SetScale(0.8);
    it->speed_item = 3;
}

void Gameloop::clearItem()
{
    auto it = ITEM.begin();
    while (it != ITEM.end())
    {
        if ((*it)->type == "rocket" || (*it)->type == "chuoi" || (*it)->type == "bom" || (*it)->type == "special")
        {
            ITEM.erase(it);
        }
        else
            it++;
    }
}

void Gameloop::initBKG()
{
    bkg *bk = new bkg;
    bk->SetImage("img/bg.png");
    bk->SetPos(0, 0);
    bk->SetRect(Gameloop::WIDTH * 2, Gameloop::HEIGHT);
    bk->speed = 1;

    bk = new bkg;
    bk->SetImage("img/base.png");
    bk->SetPos(0, 400);
    bk->SetRect(Gameloop::WIDTH * 2, bk->getDest().h);
    bk->speed = 2;
}
void Gameloop::Initialize()
{
    std::string HSCORE;
    std::ifstream o;
    o.open("font/hightscore.txt");
    o >> HightScore;
    HSCORE = "Hight Score : " + std::to_string(HightScore);
    o.close();
    texHScore = TextureManager::LoadText(HSCORE.c_str(), srcHScore);
    destHScore = {WIDTH - srcHScore.w - 20, 6, srcHScore.w, srcHScore.h};
    destScore.x = 5;
    destScore.y = 6;
    timer = 0;

    srand(time(NULL));
    initBKG();

    player *chim = new player;
    chim->SetImage("img/chim.png");
    chim->maxForm = 2;
    chim->maxSkin = 3;
    chim->init(3, 100);
    chim->SetPos(50, 50);

    pipe *pp;
    for (int i = 0; i < 1; i++)
    {
        pp = new pipe;
        pp->SetImage("img/sword.png");
        pp->SetScale(0.5);
        pp->speed_pipe = 5;
        pp->SetPos(100, 400 - pp->getDest().h);
    }

    addItem(true);
    addItem(true);

    GameState = true;
}

void Gameloop::Event()
{
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
        GameState = false;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        for (auto &chim : PLAYER)
        {
            chim->jump();
        }
        std::cout << "press start!" << std::endl;
    }
    if (event.type == SDL_KEYDOWN)
    {

        if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_SPACE)
        {
            for (auto &chim : PLAYER)
            {
                chim->jump();
            }
            std::cout << "press start!" << std::endl;
        }
    }
}

void Gameloop::Update()
{
    if (texScore != nullptr)
        SDL_DestroyTexture(texScore);
    std::string SC = "Score : " + std::to_string(score);
    texScore = TextureManager::LoadText(SC.c_str(), srcScore);
    destScore.w = srcScore.w;
    destScore.h = srcScore.h;

    // pipe
    for (auto &pp : PIPE)
    {
        pp->move();
        pp->FixData();
        if (PLAYER.back()->Collision(pp->dest))
        {
            GameState = false;
        }
    }

    if (inSpecial && (timer - start_Special) * 1000 / FPS > timeSpecial)
    {
        inSpecial = false;
        ITEM.clear();
        addItem(1);
        addItem(1);
    }
    else if (inSpecial && (timer - start_Special) % 100 == 0)
        addItem(false);

    // bkg
    for (auto &bk : BKG)
    {
        bk->slip();
        bk->FixData();
    }

    // player
    for (auto &player : PLAYER)
    {
        player->update();
        player->FixData();
    }

    // item
    for (auto &item : ITEM)
    {
        if (item->type == "bom" || item->type == "rocket")
        {
            if (item->speed_item < 7)
            {
                item->speed_item += 0.001;
            }
        }
        item->tele();
        item->FixData();
        for (auto &player : PLAYER)
        {
            if (player->scale >= 1.75)
            {
                player->form = 1;
            }

            else
            {
                player->form = 0;
            }
            if (item->Collision(player->dest))
            {
                item->respawn();
                if (item->type == "tao")
                {
                    player->scale += 0.25;
                }

                else if (item->type == "special")
                {
                    clearItem();
                    inSpecial = true;
                    start_Special = timer;
                }

                else if (item->type == "chuoi")
                {

                    item->SlowAllItem(3000);
                }

                else if (item->type == "luu")
                {
                    player->scale -= 0.25;
                    if (player->scale < 0.5)
                        player->scale = 0.5;
                }
                else if (item->type == "bom" || item->type == "rocket")
                {
                    if (player->form == 1)
                    {
                        player->scale = 1;
                        item->val = -10;
                    }
                    else
                    {
                        item->val = 0;
                        Gameloop::GameState = false;
                    }
                }
            }
        }
    }
}
void Gameloop::Render()
{
    SDL_RenderClear(renderer);

    for (auto &bk : BKG)
    {
        bk->Draw();
    }
    for (auto &player : PLAYER)
    {
        player->Draw();
    }
    for (auto &item : ITEM)
    {
        item->Draw();
    }
    for (auto &pp : PIPE)
    {
        pp->Draw();
    }
    for (auto &pp : PIPE)
    {
        pp->Draw();
    }
    SDL_RenderCopy(Gameloop::renderer, texScore, NULL, &destScore);
    SDL_RenderCopy(Gameloop::renderer, texHScore, NULL, &destHScore);

    SDL_RenderPresent(renderer);
}

void Gameloop::Close()
{
    for (auto &a : PIPE)
    {
        delete a;
    }
    PIPE.clear();
    for (auto &a : PLAYER)
    {
        delete a;
    }
    PLAYER.clear();
    for (auto &a : ITEM)
    {
        delete a;
    }
    ITEM.clear();
    for (auto &a : BKG)
    {
        delete a;
    }

    if (score > HightScore)
    {
        std::ofstream o;
        o.open("font/hightscore.txt");
        o << score;
        o.close();
    }

    BKG.clear();
    inSpecial = false;
    start_Special = -5000;
    GameState = false;
    score = 0;
    timer = 0;
    FPS = 120;
    item::slow = 1;
}

void Gameloop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}