#pragma once

#include <Types.h>
#include <BwString.h>
#include <BWAPI/Position.h>
#include <BWAPI/UnitType.h>
#include <BWAPI/Event.h>
#include <BWAPI/EventType.h>

//____________________________________________//
// Forward conversion :: BW -> TX
// Reverse conversion :: TX -> BW
// BW - types that come from BWAPI
// TX - types that come from AI bot (=a Type eXternal to BWAPI)
// for value types it looks like this: Cast<BWAPI::Position, Position>
// for opaque ref types looks like this: Cast<BWAPI::Unit, Unit*>

template<class BW, class TX>
struct Cast {
    // type members to infer Cast type instance from CastFwd and CastRev
    typedef TX TxType;
    typedef BW BwType;
    // disallow to call non-specialized version
    static TX from_bw(BW bw) = delete;
    static BW to_bw(TX tx) = delete;
};

template <class T>
struct CastFwd { typedef Cast<T, T> Type; };

template <class T>
struct CastRev { typedef Cast<T, T> Type; };

//_______________________________________________________//
// shortcut functions to make Cast usage more lightweight
// cast_from_bw :: BW -> TX
// cast_to_bw :: TX -> BW

template<class BW>
typename CastFwd<BW>::Type::TxType cast_from_bw(BW bw) {
    return CastFwd<BW>::Type::from_bw(bw);
}

template<class TX>
typename CastRev<TX>::Type::BwType cast_to_bw(TX tx) {
    return CastRev<TX>::Type::to_bw(tx);
}

//_______________________________//
// Cast specializations go here  //

template<>
struct Cast<BWAPI::Position, Position> {
    typedef BWAPI::Position BwType;
    typedef Position        TxType;

    static TxType from_bw(BwType bw) {
        return Position {bw.x, bw.y};
    }
    static BwType to_bw(TxType tx) {
        return BWAPI::Position {tx.x, tx.y};
    }
};
template<>
struct CastFwd<BWAPI::Position> {
    typedef Cast<BWAPI::Position, Position> Type;
};
template<>
struct CastRev<Position> {
    typedef Cast<BWAPI::Position, Position> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::TilePosition, TilePosition> {
    typedef BWAPI::TilePosition BwType;
    typedef TilePosition        TxType;

    static TxType from_bw(BwType bw) {
        return TilePosition {bw.x, bw.y};
    }
    static BwType to_bw(TxType tx) {
        return BWAPI::TilePosition {tx.x, tx.y};
    }
};
template<>
struct CastFwd<BWAPI::TilePosition> {
    typedef Cast<BWAPI::TilePosition, TilePosition> Type;
};
template<>
struct CastRev<TilePosition> {
    typedef Cast<BWAPI::TilePosition, TilePosition> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::UnitType, UnitType> {
    typedef BWAPI::UnitType BwType;
    typedef UnitType        TxType;

    inline static TxType from_bw(BwType bw) {
        return UnitType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::UnitType {tx.id};
    }
};
template<>
struct CastFwd<BWAPI::UnitType> {
    typedef Cast<BWAPI::UnitType, UnitType> Type;
};
template<>
struct CastRev<UnitType> {
    typedef Cast<BWAPI::UnitType, UnitType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::EventType::Enum, EventType> {
    typedef BWAPI::EventType::Enum BwType;
    typedef EventType              TxType;

    inline static TxType from_bw(BwType bw) {
        return EventType { bw };
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::EventType::Enum(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::EventType::Enum> {
    typedef Cast<BWAPI::EventType::Enum, EventType> Type;
};
template<>
struct CastRev<EventType> {
    typedef Cast<BWAPI::EventType::Enum, EventType> Type;
};
//----------------------------------------------------

template<>
struct Cast<std::string, BwString*> {
    typedef std::string BwType;
    typedef BwString*   TxType;

    // not implemented because currently
    // BWAPI::Event::text field is mapped to void*
    static TxType from_bw(BwType bw) = delete;
    static BwType to_bw(TxType tx) = delete;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Unit, Unit*> {
    typedef BWAPI::Unit BwType;
    typedef Unit*       TxType;
    static TxType from_bw(BwType bw) {
        return reinterpret_cast<Unit*>(bw);
    }
    static BwType to_bw(TxType tx) {
        return reinterpret_cast<BWAPI::Unit>(tx);
    }
};
template<>
struct CastFwd<BWAPI::Unit> {
    typedef Cast<BWAPI::Unit, Unit*> Type;
};
template<>
struct CastRev<Unit*> {
    typedef Cast<BWAPI::Unit, Unit*> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Player, Player*> {
    typedef BWAPI::Player BwType;
    typedef Player*       TxType;
    static TxType from_bw(BwType bw) {
        return reinterpret_cast<Player*>(bw);
    }
    static BwType to_bw(TxType tx) {
        return reinterpret_cast<BWAPI::Player>(tx);
    }
};
template<>
struct CastFwd<BWAPI::Player> {
    typedef Cast<BWAPI::Player, Player*> Type;
};
template<>
struct CastRev<Player*> {
    typedef Cast<BWAPI::Player, Player*> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Event, Event> {
    typedef BWAPI::Event BwType;
    typedef Event        TxType;

    static TxType from_bw(BwType bw) {
        return Event {
            cast_from_bw(bw.getPosition()),
            // impossible for bw.getText() to be NULL, since bwapi guarantees it:
            // const std::string& Event::getText() const
            //     if (text == nullptr)
            //         return emptyString;
            //     return *text;
            reinterpret_cast<void*>(const_cast<std::string*>(&bw.getText())),
            cast_from_bw(bw.getUnit()),
            cast_from_bw(bw.getPlayer()),
            cast_from_bw(bw.getType()),
            bw.isWinner()
        };
    }
    // Event is read-only type,
    // there is no need to convert it back
    static BwType to_bw(TxType tx) = delete;
};
template<>
struct CastFwd<BWAPI::Event> {
    typedef Cast<BWAPI::Event, Event> Type;
};
template<>
struct CastRev<Event> {
    typedef Cast<BWAPI::Event, Event> Type;
};
//----------------------------------------------------
