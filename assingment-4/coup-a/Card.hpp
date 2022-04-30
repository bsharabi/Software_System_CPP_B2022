#ifndef CARD_H
#define CARD_H
namespace coup
{

    enum class CardType
    {
        Duke,
        Assassin,
        Ambassador,
        Captain,
        Contessa
    };
}

namespace coup
{
    enum class ActionType
    {
        income,
        foreign_aid,
        tax,
        steal,
        block,
        transfer,
        coup,
        err,
    };
}
#endif