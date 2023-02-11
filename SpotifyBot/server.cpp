#include <iostream>
#include <boost/asio.hpp>
#include "server.h"
#include <string>
#include "config.h"

using namespace boost::asio;

const int MAX_LENGTH = 1024;

void startTelegramBot() {
    TgBot::Bot bot(constants::telegramApiKey);
    std::cout << "Telegram bot started" << std::endl;

    
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
        });

    bot.getEvents().onCommand("getHistory", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "History");
        });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
    if (StringTools::startsWith(message->text, "/start") || StringTools::startsWith(message->text, "/getHistory")) {
        return;
    }

    std::string chatDescription = bot.getApi().getChat(message->chat->id)->description;

    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });

    try {
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    }

    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

void startServer(){
    io_service service;
    ip::tcp::endpoint endpoint(ip::tcp::v4(), 8081);
    ip::tcp::acceptor acceptor(service, endpoint);

    std::cout << "Server started" << std::endl;

    std::thread thread_obj(startTelegramBot);

    while (true) {
        try {
            char data[MAX_LENGTH];
            ip::tcp::socket socket(service);
            acceptor.accept(socket);
            size_t length = socket.read_some(buffer(data));
            std::string request(data, length);
            //std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
            std::string response = "Hello there";
            socket.write_some(buffer(response));
        }

        catch (exception e) {
            printf("error: %s\n", e.what());
        }
    }
}

