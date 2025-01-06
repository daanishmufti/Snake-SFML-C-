#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <windows.h>

int speed = 200;
int count = 0;
bool gameOver = false;
const int SNAKE_SIZE = 50;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

sf::Time delay = sf::milliseconds(speed); 

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH + 100, WINDOW_HEIGHT + 230), "SNAKENAPOLIS", sf::Style::Titlebar | sf::Style::Close);
sf::Texture headTextureUp, headTextureDown, headTextureLeft, headTextureRight;
sf::Sprite headSprite;
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
sf::Texture fruitTexture;
sf::Sprite fruitSprite;
std::vector<sf::Vector2i> snake;
sf::Vector2i direction(0, 0);
sf::Font font;
sf::Text dname;
sf::Font scoref;
sf::Text scoreboard;
sf::Texture myfacet;
sf::Sprite myfaces;
sf::Texture bamt;
sf::Sprite bams;
sf::Texture goldt;
sf::Sprite golds;
sf::Texture snt;
sf::Sprite sns;
sf::Texture gameot;
sf::Sprite gameos;
sf::Music backgroundMusic;
sf::Texture tailTextureUp, tailTextureDown, tailTextureLeft, tailTextureRight;
sf::Sprite tailSpriteUp, tailSpriteDown, tailSpriteLeft, tailSpriteRight;
sf::Music crunch;
sf::Texture startt;
sf::Sprite starts;
sf::Text sped;
sf::Texture easyt;
sf::Sprite easys;
sf::Texture mediumt;
sf::Sprite mediums;
sf::Texture hardt;
sf::Sprite hards;
sf::Text seld;
sf::Texture backt;
sf::Sprite backs;
sf::Texture bdt;
sf::Sprite bds;
sf::Texture sett;
sf::Sprite sets;
sf::Texture soundt;
sf::Sprite sounds;
sf::Texture musict;
sf::Sprite musics;
sf::Texture mlt;
sf::Sprite mls;
sf::Texture mrt;
sf::Sprite mrs;
sf::Text musictext;
sf::Sprite srs;
sf::Texture srt;
sf::Sprite sls;
sf::Texture slt;
sf::Text soundtext;
sf::Texture aqrrt;
sf::Sprite aqrrs;
sf::Texture aqllt;
sf::Sprite aqlls;
sf::Texture snrt;
sf::Sprite snrs;
sf::Texture snbt;
sf::Sprite snbs;
sf::Texture sngt;
sf::Sprite sngs;
sf::Music buttonclick;
sf::Texture aqrr1t;
sf::Sprite aqrr1s;
sf::Texture aqll1t;
sf::Sprite aqll1s;
sf::Texture fruitapplet;
sf::Sprite fruitapples;
sf::Texture fruitoranget;
sf::Sprite fruitoranges;
sf::Texture fruitbanat;
sf::Sprite fruitbanas;
sf::Texture helpt;
sf::Sprite helps;
sf::Texture controlest;
sf::Sprite controless;
sf::Texture arrowt;
sf::Sprite arrows;
sf::Texture showt;
sf::Sprite shows;
sf::Text snke;
sf::Texture creditt;
sf::Sprite credits;
sf::Text creditext;
sf::Text gmaillink;
sf::Text githublink;
sf::Text linklink;
sf::Texture movingTexture;
sf::Sprite movingSprite;
sf::Music over;
sf::Texture scrollt;
sf::Sprite scrolls;
sf::Texture yellowt;
sf::Sprite yellows;
sf::Texture meneatt;
sf::Sprite meneats;
sf::Music meneatsound;
sf::Texture bartailt;
sf::Sprite bartails;
sf::Texture start;
sf::Sprite stars;


std::string intToString(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void configureWindow()
{
    HWND hwnd = static_cast<HWND>(window.getSystemHandle());
    LONG style = GetWindowLong(hwnd, GWL_STYLE);

    style &= ~WS_MAXIMIZEBOX;
    style &= ~WS_MINIMIZEBOX;

    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
}

int sp = 2;
int sc = 120;
int musicvolume = 50;
int soundvolume = 50;
int snakecolour = 1;
int fruitcolour = 1;
int r = 160;
int g = 196;
int b = 50;
bool overtrigger = false;
std::string sposw = "snake_head_up.png";
std::string sposa = "snake_head_down.png";
std::string sposs = "snake_head_left.png";
std::string sposd = "snake_head_right.png";
std::string tailw = "tailw.png";
std::string taila = "tails.png";
std::string tails = "taila.png";
std::string taild = "taild.png";
std::string fruit = "fruit.png";

void game();
void menu();
void settings();

void showLoadingScreen(sf::RenderWindow &window)
{
	snt.loadFromFile("snb.png");
    bamt.loadFromFile("bamk.png");
    goldt.loadFromFile("gold.png");
    bdt.loadFromFile("woody.png");
    meneatt.loadFromFile("fruit.png");
    bartailt.loadFromFile("taila.png");
    movingTexture.loadFromFile("snake_head_right.png");
    movingSprite.setTexture(movingTexture);
    movingSprite.setScale(0.5, 0.5);
    
    meneatsound.openFromFile("crunch.wav");
    meneatsound.setVolume(50);
	
    font.loadFromFile("art.ttf");
    sf::Text loadingText;
    loadingText.setFont(font);
    loadingText.setString("Loading, please wait...");
    loadingText.setCharacterSize(50);
    loadingText.setFillColor(sf::Color::Black);
    loadingText.setPosition(260, 630);
    
    sns.setTexture(snt);
    sns.setScale(1.2, 1.0); 
    sns.setPosition(130, 120);
    
    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8);
    bams.setPosition(-260, -180);
    
    golds.setTexture(goldt);
    golds.setScale(0.33, 0.62);
    golds.setPosition(-40, -125);

    bds.setTexture(bdt);
    bds.setScale(1.2, 1.3);
    bds.setPosition(0, 0);
    
    meneats.setTexture(meneatt);
    meneats.setScale(0.1, 0.1);
    meneats.setPosition(675, 485);
    
    bartails.setTexture(bartailt);
    bartails.setScale(0.02, 0.0235);
    bartails.setPosition(175, 496.5);

    sf::RectangleShape progressBar;
    progressBar.setSize(sf::Vector2f(500, 40));
    progressBar.setFillColor(sf::Color(r, g, b));
    progressBar.setPosition(200, 500);

    sf::RectangleShape progressBarBackground;
    progressBarBackground.setSize(sf::Vector2f(500, 40));
    progressBarBackground.setFillColor(sf::Color::Black);
    progressBarBackground.setPosition(200, 500);

    float progress = 0; 
    sf::Clock clock;

    while(progress < 1)
	{
        sf::Time deltaTime = clock.restart();
        progress += deltaTime.asSeconds() * 0.4; 
        if(progress > 1)
		{
			progress = 1;
		}

        progressBar.setSize(sf::Vector2f(500 * progress, 40));
        movingSprite.setPosition(200 + (500 * progress) - (movingSprite.getGlobalBounds().width * movingSprite.getScale().x), 487);

        window.clear(sf::Color(200, 170, 130));
        window.draw(bds);
        window.draw(golds);
        window.draw(bams);
        window.draw(sns);
        window.draw(progressBarBackground);
        window.draw(meneats);
        window.draw(progressBar);
        window.draw(loadingText);
        window.draw(movingSprite);
        window.draw(bartails);
        window.display();
        meneatsound.play();
    }
}

void credt()
{
	font.loadFromFile("art.ttf");
    creditext.setFont(font);
    creditext.setString("\t \t   Game Title: SNAKENOPOLIS \n\n \t  Developed By: Daanish Ahmad Mufti \n \t  Programming: Daanish Ahmad Mufti \n \t  Graphics: Daanish Ahmad Mufti \n \t  Sound & Music: Daanish Ahmad Mufti \n \t  Tools Used: SFML ,C++ \n   Copyright © [2024] Daanish Ahmad Mufti.\n \t \t \t \t All Rights Reserved. \n \n \tEmail:  \n \tLinkedIn:  \n \tGithub: ");
    creditext.setCharacterSize(40); 
    creditext.setFillColor(sf::Color::Black);
    creditext.setStyle(sf::Text::Bold);
    creditext.setPosition(100, 100);

    gmaillink.setFont(font);
    gmaillink.setString("daanishmufti@gmail.com");
    gmaillink.setCharacterSize(40); 
    gmaillink.setFillColor(sf::Color::Red);
    gmaillink.setStyle(sf::Text::Bold);
    gmaillink.setPosition(250, 610);
    
    githublink.setFont(font);
    githublink.setString("github.com/daanishmufti");
    githublink.setCharacterSize(40); 
    githublink.setFillColor(sf::Color::Red);
    githublink.setStyle(sf::Text::Bold);
    githublink.setPosition(270, 710);
    
    linklink.setFont(font);
    linklink.setString("www.linkedin.com/daanish-mufti");
    linklink.setCharacterSize(40); 
    linklink.setFillColor(sf::Color::Red);
    linklink.setStyle(sf::Text::Bold);
    linklink.setPosition(295, 660);
    
    dname.setFont(font);
    dname.setString("Made By Daanish Ahmad Mufti");
    dname.setCharacterSize(30); 
    dname.setFillColor(sf::Color::Black);
    dname.setStyle(sf::Text::Bold | sf::Text::Underlined);
    dname.move(160,940);
}

void cred()
{
	backt.loadFromFile("back.png");
    bamt.loadFromFile("bamk.png");
    goldt.loadFromFile("gold.png");
    bdt.loadFromFile("woody.png");
    myfacet.loadFromFile("daanish.png");
    scrollt.loadFromFile("scroll.png");
    
    myfaces.setTexture(myfacet);
    myfaces.setScale(0.4, 0.4); 
    myfaces.setPosition(55, 890);
    
    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8);
    bams.setPosition(-260, -180);

    golds.setTexture(goldt);
    golds.setScale(0.33, 0.62);
    golds.setPosition(-40, -125);

    bds.setTexture(bdt);
    bds.setScale(1.2, 1.3);
    bds.setPosition(0, 0);

    backs.setTexture(backt);
    backs.setScale(0.7, 0.4);
    backs.setPosition(600, 870); 
    
    scrolls.setTexture(scrollt);
    scrolls.setScale(0.92, 0.8);
    scrolls.setPosition(52, 75);
    
    bool setRunning = true;
    while(setRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(backs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        buttonclick.play();
                        setRunning = false;
                        menu(); 
                    }
                }
            }
            if(event.type == sf::Event::MouseButtonPressed)
			{
                if(event.mouseButton.button == sf::Mouse::Left)
				{
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(gmaillink.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
					{
						buttonclick.play();
                        #ifdef _WIN32
                            system("start mailto:daanishmufti@gmail.com");
                        #elif __APPLE__
                            system("open mailto:daanishmufti@gmail.com");
                        #else
                            system("xdg-email daanishmufti@gmail.com");
                        #endif
                    }
                    if(githublink.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
					{
						buttonclick.play();
                        #ifdef _WIN32
                            system("start https://github.com/daanishmufti");
                        #elif __APPLE__
                            system("open https://github.com/daanishmufti");
                        #else
                            system("xdg-open https://github.com/daanishmufti");
                        #endif
                    }
                    if(linklink.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
					{
						buttonclick.play();
                        #ifdef _WIN32
                            system("start https://www.linkedin.com/in/daanish-mufti-1451a0290/");
                        #elif __APPLE__
                            system("open https://www.linkedin.com/in/daanish-mufti-1451a0290/");
                        #else
                            system("xdg-open https://www.linkedin.com/in/daanish-mufti-1451a0290/");
                        #endif
                    }
                }
            }
        }

        window.clear(sf::Color(200, 170, 130));
        window.draw(bds);
        window.draw(golds);
        window.draw(bams);
        window.draw(backs);
        window.draw(scrolls);
        window.draw(creditext);
        window.draw(myfaces);
        window.draw(gmaillink);
        window.draw(githublink);
        window.draw(linklink);
        window.draw(dname);
        window.display();
    }
}

void helptt()
{
    font.loadFromFile("art.ttf");
    snke.setFont(font);
    snke.setString("Controle the snake and eat\n the fruit to icrease your\n score. If the snake eats\n itself or hits the\n boundary the game ends.");
    snke.setCharacterSize(38); 
    snke.setFillColor(sf::Color::Black);
    snke.setStyle(sf::Text::Bold);
    
    snke.move(435,165);
}

void help()
{
    backt.loadFromFile("back.png");
    bamt.loadFromFile("bamk.png");
    goldt.loadFromFile("gold.png");
    bdt.loadFromFile("woody.png");
    controlest.loadFromFile("controles.png");
    arrowt.loadFromFile("arrow.png");
    showt.loadFromFile("show.png");
    scrollt.loadFromFile("scroll.png");

    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8);
    bams.setPosition(-260, -180);

    golds.setTexture(goldt);
    golds.setScale(0.33, 0.62);
    golds.setPosition(-40, -125);

    bds.setTexture(bdt);
    bds.setScale(1.2, 1.3);
    bds.setPosition(0, 0);

    backs.setTexture(backt);
    backs.setScale(0.7, 0.4);
    backs.setPosition(600, 870); 
    
    controless.setTexture(controlest);
    controless.setScale(0.8, 0.52);
    controless.setPosition(280, 550);
    
    arrows.setTexture(arrowt);
    arrows.setScale(0.5, 0.5);
    arrows.setPosition(240, 670);
    
    shows.setTexture(showt);
    shows.setScale(0.4, 0.4);
    shows.setPosition(70, 120);
    
    scrolls.setTexture(scrollt);
    scrolls.setScale(0.53, 0.45);
    scrolls.setPosition(400, 70);

    bool setRunning = true;
    while(setRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(backs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        buttonclick.play();
                        setRunning = false;
                        settings(); 
                    }
                }
            }
        }

        window.clear(sf::Color(200, 170, 130));
        window.draw(bds);
        window.draw(golds);
        window.draw(bams);
        window.draw(backs);
        window.draw(controless);
        window.draw(arrows);
        window.draw(shows);
        window.draw(scrolls);
        window.draw(snke);
        window.display();
    }
}


void settingt()
{
	font.loadFromFile("art.ttf");
    musictext.setFont(font);
    musictext.setString(intToString(musicvolume));
    musictext.setCharacterSize(50); 
    musictext.setFillColor(sf::Color::Black);
    musictext.setStyle(sf::Text::Bold);
    
    musictext.move(450,305);
    
    soundtext.setFont(font);
    soundtext.setString(intToString(musicvolume));
    soundtext.setCharacterSize(50); 
    soundtext.setFillColor(sf::Color::Black);
    soundtext.setStyle(sf::Text::Bold);
    
    soundtext.move(450,180);
}

void menut()
{
	font.loadFromFile("art.ttf");

    sped.setFont(font);
    sped.setString("Selected Difficulty: ");
    seld.setString("Easy");
    sped.setCharacterSize(40); 
    sped.setFillColor(sf::Color::Black);
    sped.setStyle(sf::Text::Bold);
    
    seld.setFont(font);
    seld.setCharacterSize(40); 
    seld.setFillColor(sf::Color::Black);
    seld.setStyle(sf::Text::Bold);
    
    sped.move(100,650);
    
    seld.move(420,650);
}

void gamet()
{
    scoref.loadFromFile("art.ttf");
    scoreboard.setFont(scoref);
    scoreboard.setCharacterSize(40); 
    scoreboard.setFillColor(sf::Color::Black);
    scoreboard.setStyle(sf::Text::Bold);
    scoreboard.setPosition(70, 930);  

    count = 0;
    scoreboard.setString("Score: " + intToString(count));
}

void settings()
{
    backt.loadFromFile("back.png");
    bamt.loadFromFile("bamk.png");
    goldt.loadFromFile("gold.png");
    bdt.loadFromFile("woody.png");
    soundt.loadFromFile("sound.png");
    musict.loadFromFile("music.png");
    mlt.loadFromFile("ls.png");
    mrt.loadFromFile("rs.png");
    slt.loadFromFile("ls.png");
    srt.loadFromFile("rs.png");
    aqrrt.loadFromFile("aqrr.png");
    aqllt.loadFromFile("aqll.png");
    snrt.loadFromFile("soobred.png");
    snbt.loadFromFile("soobblue.png");
    sngt.loadFromFile("soob.png");
    aqrr1t.loadFromFile("aqrr.png");
    aqll1t.loadFromFile("aqll.png");
    fruitapplet.loadFromFile("fruit.png");
    fruitoranget.loadFromFile("orange.png");
    fruitbanat.loadFromFile("bana.png");
    helpt.loadFromFile("help.png");

    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8); 
    bams.setPosition(-260, -180);
    
    golds.setTexture(goldt);
    golds.setScale(0.33, 0.62); 
    golds.setPosition(-40, -125);
    
    bds.setTexture(bdt);
    bds.setScale(1.2, 1.3); 
    bds.setPosition(0, 0);
    
    backs.setTexture(backt);
    backs.setScale(0.7, 0.4);
    backs.setPosition(600, 870);
    
    sounds.setTexture(soundt);
    sounds.setScale(0.6, 0.6); 
    sounds.setPosition(60, 150);
    
    musics.setTexture(musict);
    musics.setScale(0.6, 0.45); 
    musics.setPosition(60, 280);
    
    mls.setTexture(mlt);
    mls.setScale(1.0 , 1.1);
    mls.setPosition(680, 300);
    
    mrs.setTexture(mrt);
    mrs.setScale(1.05 , 1.12);
    mrs.setPosition(730, 299);
    
    sls.setTexture(slt);
    sls.setScale(1.0 , 1.1);
    sls.setPosition(680, 175);
    
    srs.setTexture(srt);
    srs.setScale(1.05 , 1.12);
    srs.setPosition(730, 174);
    
    aqlls.setTexture(aqllt);
    aqlls.setScale(0.7 , 0.7);
    aqlls.setPosition(100, 450);
    
    aqrrs.setTexture(aqrrt);
    aqrrs.setScale(0.7 , 0.7);
    aqrrs.setPosition(660, 446);
    
    sngs.setTexture(sngt);
    sngs.setScale(0.6 , 0.6);
    sngs.setPosition(2060, 456);
    
    snrs.setTexture(snrt);
    snrs.setScale(0.6 , 0.6);
    snrs.setPosition(2060, 456);
    
    snbs.setTexture(snbt);
    snbs.setScale(0.6 , 0.6);
    snbs.setPosition(2060, 456);
    
    aqll1s.setTexture(aqll1t);
    aqll1s.setScale(0.7 , 0.7);
    aqll1s.setPosition(100, 595);
    
    aqrr1s.setTexture(aqrr1t);
    aqrr1s.setScale(0.7 , 0.7);
    aqrr1s.setPosition(660, 591);
    
    fruitapples.setTexture(fruitapplet);
    fruitapples.setScale(0.2 , 0.2);
    fruitapples.setPosition(2060, 591);
    
    fruitoranges.setTexture(fruitoranget);
    fruitoranges.setScale(0.27 , 0.25);
    fruitoranges.setPosition(2060, 591);
    
    fruitbanas.setTexture(fruitbanat);
    fruitbanas.setScale(0.32 , 0.32);
    fruitbanas.setPosition(2060, 591);
    
    helps.setTexture(helpt);
    helps.setScale(0.70, 0.55); 
    helps.setPosition(10, 865);
    
    bool setRunning = true;
    while(setRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(backs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        setRunning = false;
                        menu();
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(mrs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(musicvolume < 100) 
                        {
                            musicvolume += 10;
                        }
                        else
                        {
                        	musicvolume = 100;
						}
						musictext.setString(intToString(musicvolume));
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(mls.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(musicvolume > 0) 
                        {
                            musicvolume -= 10;
                        }
                        else
                        {
                        	musicvolume = 0;
						}
						musictext.setString(intToString(musicvolume));
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(srs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(soundvolume < 100) 
                        {
                            soundvolume += 10;
                        }
                        else
                        {
                        	soundvolume = 100;
						}
						buttonclick.setVolume(soundvolume);
						soundtext.setString(intToString(soundvolume));
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(sls.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(soundvolume > 0) 
                        {
                            soundvolume -= 10;
                        }
                        else
                        {
                        	soundvolume = 0;
						}
						buttonclick.setVolume(soundvolume);
						soundtext.setString(intToString(soundvolume));
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(aqrrs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	if(snakecolour < 3)
                    	{
                    		snakecolour++;
						}
						else
						{
							snakecolour = 1;
						}
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(aqlls.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(snakecolour > 1)
                    	{
                    		snakecolour--;
						}
						else
						{
							snakecolour = 3;
						}
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(aqrr1s.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	if(fruitcolour < 3)
                    	{
                    		fruitcolour++;
						}
						else
						{
							fruitcolour = 1;
						}
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(aqll1s.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        if(fruitcolour > 1)
                    	{
                    		fruitcolour--;
						}
						else
						{
							fruitcolour = 3;
						}
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(helps.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	setRunning = false;
                    	help();
                    }
                }
            }
        }
        if(snakecolour == 1)
	    {
	    	sngs.setPosition(250, 456);
	    	snbs.setPosition(2060, 456);
	    	snrs.setPosition(2060, 456);
	    	sposw = "snake_head_up.png";
            sposa = "snake_head_down.png";
            sposs = "snake_head_left.png";
            sposd = "snake_head_right.png";
            tailw = "tailw.png";
            taila = "tails.png";
            tails = "taila.png";
            taild = "taild.png";
            r = 160;
            g = 196;
            b = 50;
	    }
	    else if(snakecolour == 2)
	    {
	    	snbs.setPosition(250, 456);
	    	sngs.setPosition(2060, 456);
	    	snrs.setPosition(2060, 456);
	    	sposw = "snakebluew.png";
            sposa = "snakeblues.png";
            sposs = "snakebluea.png";
            sposd = "snakeblued.png";
            tailw = "tailbluew.png";
            taila = "tailblues.png";
            tails = "tailbluea.png";
            taild = "tailblued.png";
            r = 20;
            g = 133;
            b = 236;
	    }
	    else
	    {
	    	snrs.setPosition(250, 456);
	    	snbs.setPosition(2060, 456);
	    	sngs.setPosition(2060, 456);
	    	sposw = "snakeredw.png";
            sposa = "snakereds.png";
            sposs = "snakereda.png";
            sposd = "snakeredd.png";
            tailw = "tailredw.png";
            taila = "tailreds.png";
            tails = "tailreda.png";
            taild = "tailredd.png";
            r = 217;
            g = 17;
            b = 17;
	    }
        if(fruitcolour == 1)
	    {
	    	fruitapples.setPosition(400, 591);
	    	fruitoranges.setPosition(2060, 591);
	    	fruitbanas.setPosition(2060, 591);
	    	fruit = "fruit.png";
	    }
	    else if(fruitcolour == 2)
	    {
	    	fruitoranges.setPosition(380, 571);
	    	fruitapples.setPosition(2060, 591);
	    	fruitbanas.setPosition(2060, 591);
	    	fruit = "orange.png";
	    }
	    else
	    {
	    	fruitbanas.setPosition(360, 558);
	    	fruitapples.setPosition(2060, 591);
	    	fruitoranges.setPosition(2060, 591);
	    	fruit = "bana.png";
	    }	    
	    
	    window.draw(sngs);
	    window.draw(snrs);
	    window.draw(snbs);
        window.clear(sf::Color(200, 170, 130)); 
        window.draw(bds);
        window.draw(golds);
        window.draw(bams);
        window.draw(backs);
        window.draw(sounds);
        window.draw(musics);
        window.draw(mls);
        window.draw(mrs);
        window.draw(musictext);
        window.draw(sls);
        window.draw(srs);
        window.draw(soundtext);
        window.draw(aqrrs);
        window.draw(aqlls);
        window.draw(sngs);
        window.draw(snrs);
        window.draw(snbs);
        window.draw(aqrr1s);
        window.draw(aqll1s);
        window.draw(fruitapples);
        window.draw(fruitoranges);
        window.draw(fruitbanas);
        window.draw(helps);
        
        window.display();
    }
}


void menu()
{
	if(overtrigger == false)
	{
		backgroundMusic.stop(); 
	}
	startt.loadFromFile("start.png");
    myfacet.loadFromFile("daanish.png");
    bamt.loadFromFile("bamk.png");
    goldt.loadFromFile("gold.png");
    snt.loadFromFile("snb.png");
    gameot.loadFromFile("gameo.png");
    easyt.loadFromFile("Easy.png");
    mediumt.loadFromFile("Medium.png");
    hardt.loadFromFile("Hard.png");
    bdt.loadFromFile("woody.png");
    sett.loadFromFile("setting.png");
    creditt.loadFromFile("credit.png");
    
    starts.setTexture(startt);
    sf::FloatRect buttonBounds = starts.getGlobalBounds();
    starts.setPosition(280, 420);
    starts.setScale(0.6, 0.5);
    
    easys.setTexture(easyt);
    sf::FloatRect buttonBounds1 = easys.getGlobalBounds();
    easys.setPosition(80, 710);
    easys.setScale(0.9, 0.9);
    
    mediums.setTexture(mediumt);
    sf::FloatRect buttonBounds2 = mediums.getGlobalBounds();
    mediums.setPosition(305, 710);
    mediums.setScale(0.9, 1.0);
    
    hards.setTexture(hardt);
    sf::FloatRect buttonBounds3 = hards.getGlobalBounds();
    hards.setPosition(550, 700);
    hards.setScale(0.9, 0.9);
    
    sets.setTexture(sett);
    sf::FloatRect buttonBounds4 = sets.getGlobalBounds();
    sets.setPosition(30, 870);
    sets.setScale(0.65, 0.7);
    
    bds.setTexture(bdt);
    bds.setScale(1.2, 1.3); 
    bds.setPosition(0, 0);
    
    credits.setTexture(creditt);
    credits.setScale(0.75, 0.62); 
    credits.setPosition(538, 880);
    
    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8); 
    bams.setPosition(-260, -180);
    
    golds.setTexture(goldt);
    golds.setScale(0.33, 0.62); 
    golds.setPosition(-40, -125);
    
    sns.setTexture(snt);
    sns.setScale(1.2, 1); 
    sns.setPosition(130, 120);
    
    gameos.setTexture(gameot);
    gameos.setScale(1, 1); 
    gameos.setPosition(170, 230);

    bool menuRunning = true;
    while(menuRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(starts.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        menuRunning = false;
                        game();
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(easys.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        seld.setString("Easy");
                        sp = 2;
                        sc = 120;
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(mediums.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                        seld.setString("Medium");
                        sp = 5;
                        sc = 100;
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(hards.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	seld.setString("Hard");
                    	sp = 10;
                        sc = 50;
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(sets.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	menuRunning = false;
                    	settings();
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(credits.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                    	buttonclick.play(); 
                    	menuRunning = false;
                    	cred();
                    }
                }
            }
        }

        window.clear(sf::Color(200, 170, 130)); 
        window.draw(bds);
        window.draw(golds);
        window.draw(bams);
        window.draw(sns);
        window.draw(starts);
        window.draw(sped);
        window.draw(easys);
        window.draw(mediums);
        window.draw(hards);
        window.draw(seld);
        window.draw(sets);
        window.draw(credits);

        window.display();
    }
}

void updateHeadTexture()
{
    if(direction == sf::Vector2i(0, -SNAKE_SIZE))
	{
        headSprite.setTexture(headTextureUp);
    }
	else if(direction == sf::Vector2i(0, SNAKE_SIZE))
	{
        headSprite.setTexture(headTextureDown);
    }
	else if(direction == sf::Vector2i(-SNAKE_SIZE, 0))
	{
        headSprite.setTexture(headTextureLeft);
    }
	else if(direction == sf::Vector2i(SNAKE_SIZE, 0))
	{
        headSprite.setTexture(headTextureRight);
    }
}

bool isPositionOccupied(const sf::Vector2i& position) {
    for(int i = 0 ; i < snake.size() ; i++)
	{
        if(snake[i] == position)
		{
            return true;
        }
    }
    return false;
}

void placeFruit() {
    sf::Vector2i newFruitPosition;
    do
	{
        int x = rand() % (WINDOW_WIDTH / SNAKE_SIZE) * SNAKE_SIZE + 50;
        int y = rand() % (WINDOW_HEIGHT / SNAKE_SIZE) * SNAKE_SIZE + 50;
        newFruitPosition = sf::Vector2i(x, y);
    }while(isPositionOccupied(newFruitPosition) || newFruitPosition == snake.front());

    fruitSprite.setPosition(float(newFruitPosition.x), float(newFruitPosition.y));
}


void reset()
{
    if(overtrigger == true)
    {
        backgroundMusic.play();
        overtrigger = false;
	}
    snake.clear();
    direction = sf::Vector2i(0, 0);
    speed = 200;
    delay = sf::milliseconds(speed);
    count = 0;
    scoreboard.setString("Score: " + intToString(count));
    snake.push_back(sf::Vector2i(400, 300));
    placeFruit();
}

void processEvents()
{
    sf::Event event;
    
    while(window.pollEvent(event))
	{
        if(event.type == sf::Event::Closed)
		{
            window.close();
        }

        if(event.type == sf::Event::KeyPressed)
		{
            if((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) && direction != sf::Vector2i(0, SNAKE_SIZE))
			{
                direction = sf::Vector2i(0, -SNAKE_SIZE);
                updateHeadTexture();
            }
			else if((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) && direction != sf::Vector2i(0, -SNAKE_SIZE))
			{
                direction = sf::Vector2i(0, SNAKE_SIZE);
                updateHeadTexture();
            }
			else if((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) && direction != sf::Vector2i(SNAKE_SIZE, 0))
			{
                direction = sf::Vector2i(-SNAKE_SIZE, 0);
                updateHeadTexture();
            }
			else if((event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) && direction != sf::Vector2i(-SNAKE_SIZE, 0))
			{
                direction = sf::Vector2i(SNAKE_SIZE, 0);
                updateHeadTexture();
            }
           if(gameOver && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::D))
			{
				gameOver = false;
                gameos.setPosition(320, 1000); 
                reset();
            }
            if(event.key.code == sf::Keyboard::R)
            {
            	buttonclick.play(); 
                reset();
            }
        }
        
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backs.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                	buttonclick.play(); 
                	backgroundMusic.stop();
                	reset();
                    menu(); 
                }
            }  
        }
    }
}

void update()
{
    if(direction != sf::Vector2i(0, 0) && !gameOver)
    {
        sf::Vector2i newHead = snake.front() + direction;
        snake.insert(snake.begin(), newHead);

        if(newHead == sf::Vector2i(fruitSprite.getPosition().x, fruitSprite.getPosition().y))
        {
            placeFruit(); 
            speed -= sp; 
            if(speed < sc)
            {
                speed = sc; 
            }
            delay = sf::milliseconds(speed); 
            count++;
            crunch.play();
            scoreboard.setString("Score: " + intToString(count));
        }
        else
        {
            snake.pop_back(); 
        }

        for(int i = 1 ; i < snake.size() ; i++)
        {
            if(snake[i] == snake.front())
            {
            	over.play();
            	backgroundMusic.stop();
                gameOver = true;
                return;
            }
        }

        if(snake.front().x < 50 || snake.front().x >= WINDOW_WIDTH + 50 || snake.front().y < 50 || snake.front().y >= WINDOW_HEIGHT + 50)
        {
        	over.play();
        	backgroundMusic.stop();
            gameOver = true;
        }
    }
}



void render()
{
    window.clear(sf::Color(200, 170, 130)); 
    
    bdt.loadFromFile("woody.png");
    start.loadFromFile("star.png");
    bds.setTexture(bdt);
    bds.setScale(1.2, 0.5); 
    bds.setPosition(0, 870);
    window.draw(golds);
    window.draw(bds);
    window.draw(backgroundSprite);
    
    backs.setTexture(backt);
    sf::FloatRect buttonBounds = backs.getGlobalBounds();
    backs.setPosition(600, 870);
    backs.setScale(0.7, 0.4);

    for(int i = 0 ; i < snake.size() ; i++)
    {
        sf::Vector2i& segment = snake[i];
        if(i == 0)
        {
            headSprite.setPosition(float(segment.x), float(segment.y));
        }
        else
        {
            sf::Sprite tailSprite;
            if(i == snake.size() - 1) 
            {
                sf::Vector2i previousSegment = snake[i - 1];
                sf::Vector2i tailDirection = segment - previousSegment;
                
                int x = 0;
                int y = 0;

                if(tailDirection == sf::Vector2i(0, SNAKE_SIZE))
                {
                	x = -5;
                	y = -30;
                    tailSprite = tailSpriteDown;
                }
                else if(tailDirection == sf::Vector2i(0, -SNAKE_SIZE))
                {
                	x = -5;
                	y = -5;
                    tailSprite = tailSpriteUp;
                }
                else if(tailDirection == sf::Vector2i(SNAKE_SIZE, 0))
                {
                	x = -30;
                	y = -5;
                    tailSprite = tailSpriteRight;
                }
                else if(tailDirection == sf::Vector2i(-SNAKE_SIZE, 0))
                {
                	x = -5;
                	y = -5;
                    tailSprite = tailSpriteLeft;
                }

                tailSprite.setPosition(float(segment.x + x), float(segment.y + y));
                window.draw(tailSprite);
            }
            else
            {
                sf::RectangleShape shape(sf::Vector2f(SNAKE_SIZE, SNAKE_SIZE));
                shape.setFillColor(sf::Color(r, g, b)); 
                shape.setPosition(float(segment.x), float(segment.y));
                window.draw(shape);
            }
        }
    }
    window.draw(headSprite);
    window.draw(fruitSprite);
    window.draw(yellows);
    window.draw(scoreboard);
    window.draw(bams);
    window.draw(sns);
    window.draw(backs);
    
    if(gameOver == true)
    {
    	sf::Vector2i& segment = snake[0];
    	stars.setTexture(start);
        stars.setScale(0.15, 0.15);
        stars.setPosition(float(segment.x) - 35, float(segment.y) - 35);
        gameos.setPosition(170, 230);
		window.draw(gameos); 
        overtrigger = true;
    }
    else
    {
    	stars.setPosition(1000, 1000);
	}
    window.draw(stars);
    window.display();
}



sf::Texture createChessboardTexture(int tileSize, int boardSize)
{
    sf::Image chessboardImage;
    chessboardImage.create(boardSize * tileSize, boardSize * tileSize);

    for(int y = 0 ; y < boardSize ; y++)
	{
        for(int x = 0 ; x < boardSize ; x++)
		{
            sf::Color color = ((x + y) % 2 == 0) ? sf::Color::White : sf::Color::Black;
            for(int tileY = 0; tileY < tileSize; ++tileY)
			{
                for(int tileX = 0 ; tileX < tileSize; tileX++)
				{
                    chessboardImage.setPixel(x * tileSize + tileX, y * tileSize + tileY, color);
                }
            }
        }
    }

    sf::Texture chessboardTexture;
    chessboardTexture.loadFromImage(chessboardImage);
    return chessboardTexture;
}

void game()
{
    gameOver = false;
	fruitTexture.loadFromFile(fruit);
	
    backgroundMusic.openFromFile("jungle4.wav");
    backgroundMusic.setVolume(musicvolume);
    crunch.openFromFile("crunch.wav");
    crunch.setVolume(soundvolume);
    
    over.openFromFile("headhit.wav");
    over.setVolume(soundvolume);

    backgroundMusic.setLoop(true); 
    backgroundMusic.play(); 
    
    backt.loadFromFile("back.png");
    
    tailTextureUp.loadFromFile(tailw);
    tailTextureDown.loadFromFile(taila);
    tailTextureLeft.loadFromFile(tails);
    tailTextureRight.loadFromFile(taild);

    float tailScaleX = static_cast<float>(SNAKE_SIZE) / tailTextureUp.getSize().x;
    float tailScaleY = static_cast<float>(SNAKE_SIZE) / tailTextureUp.getSize().y;

    tailSpriteUp.setTexture(tailTextureUp);
    tailSpriteUp.setScale(tailScaleX + 0.005, tailScaleY + 0.020);

    tailSpriteDown.setTexture(tailTextureDown);
    tailSpriteDown.setScale(tailScaleX + 0.005, tailScaleY + 0.020);

    tailSpriteLeft.setTexture(tailTextureLeft);
    tailSpriteLeft.setScale(tailScaleX + 0.020, tailScaleY + 0.005);

    tailSpriteRight.setTexture(tailTextureRight);
    tailSpriteRight.setScale(tailScaleX + 0.020, tailScaleY + 0.005);
	
	bamt.loadFromFile("bamk.png");
    bams.setTexture(bamt);
    bams.setScale(2.25, 1.8); 
    bams.setPosition(-260, -180);
	
	goldt.loadFromFile("gold.png");
    golds.setTexture(goldt);
    golds.setScale(0.33, 0.53); 
    golds.setPosition(-40, -100);
	
	snt.loadFromFile("snb.png");
    sns.setTexture(snt);
    sns.setScale(0.5, 0.3); 
    sns.setPosition(320, 820);       
    
    gameot.loadFromFile("gameo.png");
    gameos.setTexture(gameot);
    gameos.setScale(1, 1); 
	gameos.setPosition(170, 230);  
	
	yellowt.loadFromFile("yellow.png");
    yellows.setTexture(yellowt);
    yellows.setScale(0.66, 0.65); 
	yellows.setPosition(50, 920);  
    
    srand(static_cast<unsigned>(time(0)));

    snake.push_back(sf::Vector2i(400, 300));

    headTextureUp.loadFromFile(sposw);
    headTextureDown.loadFromFile(sposa);
    headTextureLeft.loadFromFile(sposs);
    headTextureRight.loadFromFile(sposd);

    headSprite.setTexture(headTextureUp);
    headSprite.setScale(SNAKE_SIZE * 1.7 / float(headTextureUp.getSize().x), SNAKE_SIZE * 1.7 / float(headTextureUp.getSize().y));
    headSprite.setOrigin(headTextureUp.getSize().x * SNAKE_SIZE / headTextureUp.getSize().x / 2,headTextureUp.getSize().y * SNAKE_SIZE / headTextureUp.getSize().y / 2);

    backgroundTexture = createChessboardTexture(SNAKE_SIZE, 16); 
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(float(WINDOW_WIDTH) / backgroundTexture.getSize().x,float(WINDOW_HEIGHT) / backgroundTexture.getSize().y);
    backgroundSprite.setPosition(50,50);

    fruitSprite.setTexture(fruitTexture);
    fruitSprite.setScale(float(SNAKE_SIZE) / fruitTexture.getSize().x,float(SNAKE_SIZE) / fruitTexture.getSize().y);
    placeFruit();

    sf::Clock clock;

    while(window.isOpen())
	{
        sf::Time deltaTime = clock.restart(); 
        processEvents();
        update();
        render();
        sf::sleep(delay);
    }
}

int main()
{
	configureWindow();
	showLoadingScreen(window);
	buttonclick.openFromFile("bt.wav");
    buttonclick.setVolume(soundvolume);
    credt();
    helptt();
	settingt();
	gamet();
	menut();
	menu();
    return 0;
}

