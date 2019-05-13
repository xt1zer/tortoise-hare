#include <SFML/Window/Event.hpp>
#include <Application.h>

#include <Message.h>

Application::Application()
    : mWindow(sf::VideoMode(1280, 720), "Tortoise & Hare"),
    mWindowSize(mWindow.getSize()),
    gameOver(true), isEnterPressed(false) {

    srand(std::time(NULL));
    mWindow.setFramerateLimit(60);

    Flag flagTortoise(mWindowSize.x - 85, 140, "Media/flag.png");
    Flag flagHare(mWindowSize.x - 85, 290, "Media/flag.png");

    packageOfApples.generate_food(&apple);
    packageOfCarrots.generate_food(&carrot);

    ground.generate_ground(mWindowSize);

    sf::Clock clock;
    while (mWindow.isOpen()) {
        time = clock.getElapsedTime().asMicroseconds() / 800;
        clock.restart();

        sf::Event event;
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            gameOver = false;
            isEnterPressed = true;
        }

        if (!gameOver) {
            update(time);
        }

        render(flagTortoise, flagHare);
    }
}

void Application::update(const float &time) {
    if (tortoise.eat_snack(&packageOfApples))
        tortoise.activate_bonus(true);

    if (tortoise.is_bonus_active()) {
        tortoise.set_current_bonus_time(time);
        if (tortoise.get_current_bonus_time() >= tortoise.get_total_bonus_time())
            tortoise.activate_bonus(false);
    }

    if (!tortoise.is_bonus_active())
        tortoise.get_random_movement();

    if (hare.eat_snack(&packageOfCarrots))
        hare.activate_bonus(true);

    if (hare.is_bonus_active()) {
        hare.set_current_bonus_time(time);
        if (hare.get_current_bonus_time() >= hare.get_total_bonus_time())
            hare.activate_bonus(false);
    }

    if (!hare.is_bonus_active())
        hare.get_random_movement();

    tortoise.animate(time);
    hare.animate(time);
    tortoise.update(time);
    hare.update(time);
}

void Application::render(const Flag &flagTortoise, const Flag &flagHare) {
    mWindow.clear();
    ground.draw(&mWindow);
    packageOfApples.draw(&mWindow);
    packageOfCarrots.draw(&mWindow);
    mWindow.draw(flagTortoise.get_sprite());
    mWindow.draw(flagHare.get_sprite());
    mWindow.draw(tortoise.get_sprite());
    mWindow.draw(hare.get_sprite());

    if (!isEnterPressed)
        startMsg.printMsg(&mWindow);

    endGame();

    mWindow.display();
}

void Application::endGame() {
    if (tortoise.is_winner() && hare.is_winner()) {
        Message message(550, 240, "Tortoise and Hare win!");
        message.printMsg(&mWindow);
        gameOver = true;
    }
    else if (tortoise.is_winner()) {
        Message message(550, 240, "Tortoise wins!");
        message.printMsg(&mWindow);
        gameOver = true;

    }
    else if (hare.is_winner()) {
        Message message(550, 240, "Hare wins!");
        message.printMsg(&mWindow);
        gameOver = true;
    }
}
