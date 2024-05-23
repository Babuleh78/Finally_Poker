#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameMenu.h"
#include "GameProcess.h"
#include "AI.h"
#include<thread>
#include <iostream>
#include "Graphics.h"
using namespace sf;
void GameStart(RenderWindow& window, int What_deck);
void TextOptions(Text& menu, float xpos, float ypos, String str, int size_front = 60,
    Color menu_text_color = Color::White, int bord = 10, Color border_color = Color::Black) {
    menu.setCharacterSize(size_front); 
    menu.setPosition(xpos, ypos); 
    menu.setString(str); 
    menu.setFillColor(menu_text_color);
    menu.setOutlineThickness(10);
    menu.setOutlineColor(border_color);
}

int main()
{
    int podsvet[7]{}, combination_number = 0;
    int What_deck = 0;
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), L"Покер", Style::Default);

    float wigth = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    //Фон меню
    RectangleShape background(Vector2f(wigth, height));
    Texture texture_window;
    if (!texture_window.loadFromFile("image/Back.jpg")) return 1;
    background.setTexture(&texture_window);

   
    setlocale(LC_ALL, "Russian");
   
 
    Font font;
    if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return 2;
    Text Titul;
    Titul.setFont(font);
    TextOptions(Titul, 780, 50, "Poker", 150, Color(255, 0, 0), 3);
    String name_menu[4]{ "Start","Cards", "Developers", "Exit" };
    game::GameMenu mymenu(window, 950, 350, name_menu, 100, 120);
    mymenu.setColorTextMenu(Color(210, 100, 40), Color::Black, Color(100, 100, 30));
    mymenu.AlignMenu(2);
    while (window.isOpen()) {
        Event event;
        Vector2i mousePoz = Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp();}
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                if (event.key.code == Keyboard::Return) {
                    switch (mymenu.getSelectedMenuNumber()) {
                    case 0:GameStart(window, What_deck); break;
                    case 1: Graphics::Texture_Card(window, What_deck); break;
                    case 2: Graphics::Developers(window); break;
                    case 3:window.close();break;
                    }
                
                }
            }
            if (event.type == Event::Closed || event.key.code == Keyboard::Escape) {
                window.close();
            }
            
        }
       
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
       
    }
    return 0;
}
void GameStart(RenderWindow& window, int What_deck) {
    int check = 1;
    RectangleShape Back(Vector2f(1920, 1080));
    sf::CircleShape button_call(50);
    sf::CircleShape button_bet(50);
    sf::CircleShape button_fold(50);
    button_call.setPosition(1400, 750);
    sf::Texture texture_call;
    if (!texture_call.loadFromFile("image/Call.jpg")) return;
    button_call.setTexture(&texture_call);
    sf::Texture texture_bet;
    if (!texture_bet.loadFromFile("image/Bet.jpg")) return;
    button_bet.setTexture(&texture_bet);
    sf::Texture texture_fold;
    if (!texture_fold.loadFromFile("image/Fold.jpg")) return;
    button_fold.setTexture(&texture_fold);
    button_bet.setPosition(1550, 750);
    button_fold.setPosition(1700, 750);
    GameProcess::card deck[52];
    bool blind_check = true, open_check = true, bot_bet_check = true, first_bot_bet_on_turn = true, fold_check = false;
    while (check) {
        int opencard = 0;
        GameProcess::card::Create(deck, What_deck);
        Texture texture;
        GameProcess::card AI_card[2]; AI_card[0] = deck[0]; AI_card[1] = deck[1];
        GameProcess::card player_card[2]; player_card[0] = deck[2]; player_card[1] = deck[3];
        GameProcess::card table_card[5];
        for (int i = 4; i < 9; i++) {
            table_card[i - 4] = deck[i];
           
        }
        int botbet = 0, playbet = 0, botcap = 3000, playcap = 3000, whoblind = 0, Betonturn = 0;
       

        if (!texture.loadFromFile("image/test.jpg")) exit(1);
        Back.setTexture(&texture);
  
        while (window.isOpen()) {
            sf::CircleShape button(75);
            sf::Texture texture1;
            if (!texture1.loadFromFile("image/button.png")) return;
            button.setTexture(&texture1);
            button.setPosition(150, 800);
            if (botcap == 0 || playcap == 0) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                sf::Font font;
                if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return;
                sf::Text Win_text;
                Win_text.setCharacterSize(120);
                Win_text.setFont(font);
     
                Win_text.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f));
                if (botcap == 0) {
                    Win_text.setFillColor(sf::Color(20, 102, 5));

                    Win_text.setString("YOU ARE BEST!");
                    
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    
                }
                else {
                    Win_text.setFillColor(sf::Color(117, 11, 11));

                    Win_text.setString("BOT ARE BETTER THAN YOU!");

                    
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    
                }
                window.draw(Win_text);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return;
            }
            if (fold_check) {
                fold_check = false;
                GameProcess::card::Create(deck, What_deck);
                AI_card[0] = deck[0]; AI_card[1] = deck[1];
                player_card[0] = deck[2]; player_card[1] = deck[3];
                for (int i = 4; i < 9; i++) {
                    table_card[i - 4] = deck[i];

                }
            }
            Event event_play;
            Vector2i mousePoz = Mouse::getPosition(window);
           
            Betonturn = 0;
            if (blind_check) {
                
                playbet = botbet = 0;

                GameProcess::card::Blind(botcap, botbet, playcap, playbet, whoblind);
                mousePoz = Mouse::getPosition(window);
                Vector2i mousePoz = Mouse::getPosition(window);
                //draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                blind_check = false;
                bot_bet_check = true;
                while (botbet != playbet || Betonturn == 0) {

                    mousePoz = Mouse::getPosition(window);
                    if (whoblind == 0) {//ставить должен игрок
                        window.clear();
            
                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                        while (window.pollEvent(event_play)) {
                            if (event_play.type == Event::KeyPressed) {
                                if (event_play.key.code == Keyboard::Escape) {
                                    window.close();
                                }
                            }
                            if (event_play.type == sf::Event::MouseButtonPressed) {
                                if (event_play.key.code == sf::Mouse::Left) {
                                    if (button.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                        return;
                                    }
                                }


                            }
                            if (event_play.type == sf::Event::MouseButtonPressed) {
                                
                                if (event_play.key.code == sf::Mouse::Left) {
                                    if (button_fold.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                        
                                        GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, 0);
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                        std::this_thread::sleep_for(std::chrono::seconds(1));
                              
                                        opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                        GameProcess::card::Create(deck, What_deck);
                                        AI_card[0] = deck[0]; AI_card[1] = deck[1];
                                        player_card[0] = deck[2]; player_card[1] = deck[3];
                                        for (int i = 4; i < 9; i++) {
                                            table_card[i - 4] = deck[i];
                                            
                                        }
                                        bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                        if (whoblind == 0) {
                                            whoblind = 1;
                                        }
                                        else {
                                            whoblind = 0;
                                        }
                                        

                                    }
                                    if (button_bet.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                        Graphics::BetWindow(playcap, playbet, botbet);
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                        if (first_bot_bet_on_turn || botbet != playbet) {
                                            
                                            AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                            
                                            if (whoblind == 1) {
                                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);

                                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                                opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                                GameProcess::card::Create(deck, What_deck);
                                                bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                            }
                                            first_bot_bet_on_turn = false;
                                            
                                        }
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                        Betonturn += 1;
                                        

                                    }
                                    if (button_call.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                        int b = botbet - playbet;
                                        playbet += b;
                                        playcap -= b;
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);                                        
                                        if (first_bot_bet_on_turn || playbet!=botbet) {
                                            AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                            first_bot_bet_on_turn = false;
                                        }
                                        Vector2i mousePoz = Mouse::getPosition(window);
        
                                        Betonturn += 1;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (botbet != playbet && first_bot_bet_on_turn) {
                           
                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                            AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                            
                            if (whoblind == 0) {
                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                GameProcess::card::Create(deck, What_deck);
                                bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                            }
                            else {
                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                first_bot_bet_on_turn = false;
                            }
                            
                        }
                        if (whoblind == 1) {
                            
                            while (window.pollEvent(event_play)) {
                                if (event_play.type == Event::KeyPressed) {
                                    if (event_play.key.code == Keyboard::Escape) {
                                        window.close();
                                    }
                                }
                               
                                if (event_play.type == sf::Event::MouseButtonPressed) {
                                    if (event_play.key.code == sf::Mouse::Left) {
                                        if (button_fold.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                            Vector2i mousePoz = Mouse::getPosition(window);
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                            GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, 0);
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                            std::this_thread::sleep_for(std::chrono::seconds(1));
                                            opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                            GameProcess::card::Create(deck, What_deck);
                                            AI_card[0] = deck[0]; AI_card[1] = deck[1];
                                            player_card[0] = deck[2]; player_card[1] = deck[3];
                                            for (int i = 4; i < 9; i++) {
                                                table_card[i - 4] = deck[i];
                                                
                                            }
                                            bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                            if (whoblind == 0) {
                                                whoblind = 1;
                                            }
                                            else {
                                                whoblind = 0;
                                            }


                                        }
                                        if (button_bet.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                            Graphics::BetWindow(playcap, playbet, botbet);
                                            Vector2i mousePoz = Mouse::getPosition(window);
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                            if (first_bot_bet_on_turn || botbet != playbet) {
                                                AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                                
                                                if (whoblind == 0) {
                                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                                    std::this_thread::sleep_for(std::chrono::seconds(1));
                                                    opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                                    GameProcess::card::Create(deck, What_deck);
                                                    bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                                }
                                                else {

                                                    first_bot_bet_on_turn = false;
                                                }

                                            }

                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                            Betonturn += 1;


                                        }
                                        if (button_call.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                            int b = botbet - playbet;
                                            playbet += b;
                                            playcap -= b;

                                            Vector2i mousePoz = Mouse::getPosition(window);
                                            if (first_bot_bet_on_turn) {
                                                first_bot_bet_on_turn = false;
                                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                            }
                                            
                                            Betonturn += 1;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            bot_bet_check = true;
           
            Betonturn = 0;
            if (opencard < 5 && open_check && playbet != 0) {
                if (whoblind == 0) {
                    first_bot_bet_on_turn = true;
                }
            
                opencard = 3;
                open_check = false;
            }
       
            bool end_of_bet = false;
            if (whoblind == 1) {
                first_bot_bet_on_turn = true;
                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
            }
            while ((botbet != playbet || Betonturn == 0)&& botbet!=0){
  
                mousePoz = Mouse::getPosition(window);
                if (whoblind == 1) {//ставить должен игрок
                    while (window.pollEvent(event_play)) {
                        if (event_play.type == Event::KeyPressed) {
                            if (event_play.key.code == Keyboard::Escape) {
                                window.close();
                            }
                        }
                       
                        if (event_play.type == sf::Event::MouseButtonPressed) {
                            if (event_play.key.code == sf::Mouse::Left) {
                                if (button_fold.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    Vector2i mousePoz = Mouse::getPosition(window);
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                    GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, 0);
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                    std::this_thread::sleep_for(std::chrono::seconds(1));
                                    opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                    GameProcess::card::Create(deck, What_deck);
                                    AI_card[0] = deck[0]; AI_card[1] = deck[1];
                                    player_card[0] = deck[2]; player_card[1] = deck[3];
                                    for (int i = 4; i < 9; i++) {
                                        table_card[i - 4] = deck[i];
                                        
                                    }
                                    bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                    if (whoblind == 0) {
                                        whoblind = 1;
                                    }
                                    else {
                                        whoblind = 0;
                                    }
                                }
                                if (button_bet.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    Graphics::BetWindow(playcap, playbet, botbet);
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                    if (first_bot_bet_on_turn || botbet != playbet) {
                                        AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                        if (whoblind == 0) {
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                            std::this_thread::sleep_for(std::chrono::seconds(1));
                                            opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                            GameProcess::card::Create(deck, What_deck);
                                            bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                        }
                                        else {
                                            
                                            if (botbet == playbet) {
                                                first_bot_bet_on_turn = true;
                                                Betonturn = 0;
                                                end_of_bet = true;
                                            }
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                            first_bot_bet_on_turn = false;
                                        }
                                    }
                                    Vector2i mousePoz = Mouse::getPosition(window);
                                    Betonturn += 1;


                                }
                                if (button_call.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    int b = botbet - playbet;
                                    playbet += b;
                                    playcap -= b;
                                    
                                    if (first_bot_bet_on_turn || botbet != playbet) {
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                        AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                       
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                        first_bot_bet_on_turn = false;
                                    }
                                    else {
                                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                        end_of_bet = false;
                                    }
                                    //AIThink(botcap, botbet, playbet);
                                    if (botbet == playbet) {
                                        end_of_bet = true;
                                        
                                    }
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                                    Betonturn += 1;
                                    
                                }
                            }
                        }
                        if (botbet == playbet && end_of_bet && opencard!=6 && !open_check) {
                            
                            
                                end_of_bet = false;
                                first_bot_bet_on_turn = true;
                                opencard += 1;
                               
                                Betonturn = 0;
                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                            
                        }
                        else if (opencard == 6) {
                            int combination_number = 0;
                            int podsvet[7]{};
                            int a = GameProcess::card::WhoWin(player_card, AI_card, table_card, opencard, combination_number);
                            if (a) {
                                Graphics::Opred_cards(podsvet, combination_number, player_card, table_card);
                            }
                            else {
                                Graphics::Opred_cards(podsvet, combination_number, AI_card, table_card);
                            }
        
                            Graphics::draw_all_Win(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1, a, podsvet, combination_number);
                            std::this_thread::sleep_for(std::chrono::seconds(7));
                            GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, a);
                           
                            opencard = 0;
                            GameProcess::card::Create(deck, What_deck);
                            AI_card[2]; AI_card[0] = deck[0]; AI_card[1] = deck[1];
                            player_card[2]; player_card[0] = deck[2]; player_card[1] = deck[3];
                            for (int i = 4; i < 9; i++) {
                                table_card[i - 4] = deck[i];
                            }
                            bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true, Betonturn = 100;
                            if (whoblind == 0) {
                                whoblind = 1;
                            }
                            else {
                                whoblind = 0;
                            }
                        }
                    }
                    
                }

                else {
                    

                    if (first_bot_bet_on_turn && bot_bet_check) {
                        
                        Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                        AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                        
                        if (whoblind == 1) { 
                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                            GameProcess::card::Create(deck, What_deck);
                            bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                        }
                        else {
                            bot_bet_check = false;
                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                            if (botbet != playbet) {
                                first_bot_bet_on_turn = false;
                            }
                        }
                        
                    }
                    while (window.pollEvent(event_play)) {
                        
                        if (event_play.type == Event::KeyPressed) {
                            if (event_play.key.code == Keyboard::Escape) {
                                window.close();
                            }
                        }
                        if (event_play.type == sf::Event::MouseButtonPressed) {
                            if (event_play.key.code == sf::Mouse::Left) {
                                if (button_fold.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    Vector2i mousePoz = Mouse::getPosition(window);

                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                    GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, 0);
                                    std::this_thread::sleep_for(std::chrono::seconds(1));
                                    opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                    GameProcess::card::Create(deck, What_deck);
                                    AI_card[0] = deck[0]; AI_card[1] = deck[1];
                                    player_card[0] = deck[2]; player_card[1] = deck[3];
                                    for (int i = 4; i < 9; i++) {
                                        table_card[i - 4] = deck[i];
   
                                    }
                                    bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                    if (whoblind == 0) {
                                        whoblind = 1;
                                    }
                                    else {
                                        whoblind = 0;
                                    }

                                }
                                if (button_bet.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    Graphics::BetWindow(playcap, playbet, botbet);
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                    if (first_bot_bet_on_turn || botbet != playbet) {
                                        AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                        if (whoblind == 1) {
                                            Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1);
                                            std::this_thread::sleep_for(std::chrono::seconds(1));
                                            opencard = 0, botbet = 0, playbet = 0, Betonturn = -1;
                                            GameProcess::card::Create(deck, What_deck);
                                            bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                                        }
                                        else {
                                            first_bot_bet_on_turn = false;
                                            if (botbet == playbet) {
                                                end_of_bet = false;
                                                opencard += 1;

                                                Betonturn = 0;
                                                first_bot_bet_on_turn = true;
                                            }
                                        }
                                    }
                                    Vector2i mousePoz = Mouse::getPosition(window);
                                    Betonturn += 1;


                                }
                                if (button_call.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                                    int b = botbet - playbet;
                                    playbet += b;
                                    playcap -= b;
                                    Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 1);
                                    
                                    if (botbet != playbet) {
                                        AI::AIBet(botcap, botbet, playcap, playbet, opencard, AI_card, table_card, whoblind, fold_check);
                                        
                                        first_bot_bet_on_turn = false;
                                    }

                                    if (botbet == playbet) {
                                        end_of_bet = false;
                                        opencard += 1;
                     
                                        Betonturn = 0;
                                        first_bot_bet_on_turn = true;
                                    }
                      
                                    
                                    Betonturn += 1;

                                }
                            }
                        }
                        if (botbet == playbet && end_of_bet && opencard != 6 && !open_check) {
                            
                            
                                end_of_bet = false;
                                first_bot_bet_on_turn = true;
                                opencard += 1;

                                Betonturn = 0;
                                Graphics::draw_all(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, 0);
                            
                        }
                        
                         if (opencard == 6) {
                             int combination_number = 0;
                             int podsvet[7]{};
                             int a = GameProcess::card::WhoWin(player_card, AI_card, table_card, opencard, combination_number);
                             if (a) {
                                 Graphics::Opred_cards(podsvet, combination_number, player_card, table_card);
                             }
                             else {
                                 Graphics::Opred_cards(podsvet, combination_number, AI_card, table_card);
                             }

                             Graphics::draw_all_Win(window, Back, button_fold, button_bet, button_call, opencard, deck, botbet, playbet, botcap, playcap, -1, a,  podsvet, combination_number);
                             std::this_thread::sleep_for(std::chrono::seconds(3));
                             GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, a);
                        
                             opencard = 0;
                             GameProcess::card::Create(deck, What_deck);
                             AI_card[2]; AI_card[0] = deck[0]; AI_card[1] = deck[1];
                             player_card[2]; player_card[0] = deck[2]; player_card[1] = deck[3];
                             
                             for (int i = 4; i < 9; i++) {
                                 table_card[i - 4] = deck[i];
                             }
                             bot_bet_check = true, blind_check = true, first_bot_bet_on_turn = true, open_check = true;
                             if (whoblind == 0) {
                                 whoblind = 1;
                             }
                             else {
                                 whoblind = 0;
                             }
                        }
                    }
                }
               
            }
            
            
        }
    }
}
