#include "MenuItem.hpp"
#include "Utilities.hpp"

#include <Windows.h>

static const uint8_t COLOR_ITEM_NOT_SELECTED = 14;
static const uint8_t COLOR_ITEM_SELECTED = 12;

static const std::string START = "START";
static const std::string OPTION = "OPTIONS";
static const std::string EXIT = "EXIT";

Menu::Menu(const Coordonates2D position)
    : currentState(static_cast<decltype(currentState)>(Status::GAME))
{
    insertItems(position);

    showAllItems();
}

Menu::~Menu()
{
    wipe();
}

Status Menu::selectState(const uint16_t waitingTimeMS)
{
    selectItem(Status::GAME);

    while (true)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            selectItem(static_cast<Status>(--currentState));
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            selectItem(static_cast<Status>(++currentState));
        }

        if (GetAsyncKeyState(VK_RETURN))
        {
            break;
        }

        sleepThread(waitingTimeMS);
    }

    return static_cast<Status>(currentState);
}

void Menu::showAllItems() const
{
    for (auto iter : mItems)
    {
        iter.second.printItem(COLOR_ITEM_NOT_SELECTED);
    }
}

void Menu::selectItem(const Status currentSelectedItem)
{
    static Status lastItemSelected = Status::GAME;
   
    if (currentSelectedItem < Status::GAME)
    {
        currentState = static_cast<decltype(currentState)>(Status::GAME);
    }
    else if (currentSelectedItem > Status::EXIT)
    {
        currentState = static_cast<decltype(currentState)>(Status::EXIT);
    }
    else
    {
        auto iter = mItems.find(lastItemSelected);
        iter->second.printItem(COLOR_ITEM_NOT_SELECTED);

        iter = mItems.find(currentSelectedItem);
        iter->second.printItem(COLOR_ITEM_SELECTED);

        lastItemSelected = currentSelectedItem;
    }
}

void Menu::wipe() const
{
    for (auto iter : mItems)
    {
        iter.second.wipeItem();
    }
}

void Menu::insertItems(const Coordonates2D position)
{
    const uint8_t offset = 2;
    mItems.insert({ Status::GAME, Item(position, START) });

    Coordonates2D pos(position.x, position.y + offset);
    mItems.insert({ Status::OPTIONS, Item(pos, OPTION) });

    pos = Coordonates2D(pos.x, pos.y + offset);
    mItems.insert({ Status::EXIT, Item(pos, EXIT) });
}
