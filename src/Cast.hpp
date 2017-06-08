#pragma once

#include <Types.h>
#include <BwString.h>
#include <BWAPI/Position.h>
#include <BWAPI/UnitType.h>
#include <BWAPI/Event.h>
#include <BWAPI/EventType.h>
#include <BWAPI/BulletType.h>
#include <BWAPI/UnitCommand.h>
#include <BWAPI/UnitCommandType.h>
#include <BWAPI/Order.h>
#include <BWAPI/Input.h>
#include <BWAPI/WeaponType.h>
#include <BWAPI/PlayerType.h>
#include <BWAPI/TechType.h>
#include <BWAPI/UpgradeType.h>
#include <BWAPI/Race.h>
#include <BWAPI/Color.h>
#include <BWAPI/GameType.h>
#include <BWAPI/CoordinateType.h>
#include <BWAPI/Error.h>

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

    inline static TxType from_bw(BwType bw) {
        return Position {bw.x, bw.y};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::Position(tx.x, tx.y);
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

    inline static TxType from_bw(BwType bw) {
        return TilePosition {bw.x, bw.y};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::TilePosition(tx.x, tx.y);
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
struct Cast<BWAPI::WalkPosition, WalkPosition> {
    typedef BWAPI::WalkPosition BwType;
    typedef WalkPosition        TxType;

    inline static TxType from_bw(BwType bw) {
        return WalkPosition {bw.x, bw.y};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::WalkPosition {tx.x, tx.y};
    }
};
template<>
struct CastFwd<BWAPI::WalkPosition> {
    typedef Cast<BWAPI::WalkPosition, WalkPosition> Type;
};
template<>
struct CastRev<WalkPosition> {
    typedef Cast<BWAPI::WalkPosition, WalkPosition> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::CoordinateType::Enum, CoordinateType> {
    typedef BWAPI::CoordinateType::Enum BwType;
    typedef CoordinateType              TxType;

    inline static TxType from_bw(BwType bw) {
        return CoordinateType {bw};
    }
    inline static BwType to_bw(TxType tx) {
        return static_cast<BWAPI::CoordinateType::Enum>(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::CoordinateType::Enum> {
    typedef Cast<BWAPI::CoordinateType::Enum, CoordinateType> Type;
};
template<>
struct CastRev<CoordinateType> {
    typedef Cast<BWAPI::CoordinateType::Enum, CoordinateType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Error, Error> {
    typedef BWAPI::Error BwType;
    typedef Error        TxType;

    inline static TxType from_bw(BwType bw) {
        return Error {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return static_cast<BWAPI::Error>(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::Error> {
    typedef Cast<BWAPI::Error, Error> Type;
};
template<>
struct CastRev<Error> {
    typedef Cast<BWAPI::Error, Error> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::BulletType, BulletType> {
    typedef BWAPI::BulletType BwType;
    typedef BulletType        TxType;

    inline static TxType from_bw(BwType bw) {
        return BulletType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::BulletType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::BulletType> {
    typedef Cast<BWAPI::BulletType, BulletType> Type;
};
template<>
struct CastRev<BulletType> {
    typedef Cast<BWAPI::BulletType, BulletType> Type;
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
        return BWAPI::UnitType(tx.id);
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
struct Cast<BWAPI::UpgradeType, UpgradeType> {
    typedef BWAPI::UpgradeType BwType;
    typedef UpgradeType        TxType;

    inline static TxType from_bw(BwType bw) {
        return UpgradeType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::UpgradeType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::UpgradeType> {
    typedef Cast<BWAPI::UpgradeType, UpgradeType> Type;
};
template<>
struct CastRev<UpgradeType> {
    typedef Cast<BWAPI::UpgradeType, UpgradeType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Race, Race> {
    typedef BWAPI::Race BwType;
    typedef Race        TxType;

    inline static TxType from_bw(BwType bw) {
        return Race {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::Race(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::Race> {
    typedef Cast<BWAPI::Race, Race> Type;
};
template<>
struct CastRev<Race> {
    typedef Cast<BWAPI::Race, Race> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::Color, Color> {
    typedef BWAPI::Color BwType;
    typedef Color        TxType;

    inline static TxType from_bw(BwType bw) {
        return Color {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::Color(tx.color);
    }
};
template<>
struct CastFwd<BWAPI::Color> {
    typedef Cast<BWAPI::Color, Color> Type;
};
template<>
struct CastRev<Color> {
    typedef Cast<BWAPI::Color, Color> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::GameType, GameType> {
    typedef BWAPI::GameType BwType;
    typedef GameType        TxType;

    inline static TxType from_bw(BwType bw) {
        return GameType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::GameType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::GameType> {
    typedef Cast<BWAPI::GameType, GameType> Type;
};
template<>
struct CastRev<GameType> {
    typedef Cast<BWAPI::GameType, GameType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::EventType::Enum, EventType> {
    typedef BWAPI::EventType::Enum BwType;
    typedef EventType              TxType;

    inline static TxType from_bw(BwType bw) {
        return EventType {bw};
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
struct Cast<BWAPI::Order, Order> {
    typedef BWAPI::Order BwType;
    typedef Order        TxType;

    inline static TxType from_bw(BwType bw) {
        return Order {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::Order(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::Order> {
    typedef Cast<BWAPI::Order, Order> Type;
};
template<>
struct CastRev<Order> {
    typedef Cast<BWAPI::Order, Order> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::UnitCommandType, UnitCommandType> {
    typedef BWAPI::UnitCommandType BwType;
    typedef UnitCommandType        TxType;

    inline static TxType from_bw(BwType bw) {
        return UnitCommandType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::UnitCommandType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::UnitCommandType> {
    typedef Cast<BWAPI::UnitCommandType, UnitCommandType> Type;
};
template<>
struct CastRev<UnitCommandType> {
    typedef Cast<BWAPI::UnitCommandType, UnitCommandType> Type;
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
struct Cast<BWAPI::UnitCommand, UnitCommand> {
    typedef BWAPI::UnitCommand BwType;
    typedef UnitCommand        TxType;

    inline static TxType from_bw(BWAPI::UnitCommand bw) {
        UnitCommand self;
        self.unit = cast_from_bw(bw.unit);
        self.type = cast_from_bw(bw.type);
        self.target = cast_from_bw(bw.target);
        self.x = bw.x;
        self.y = bw.y;
        self.extra = bw.extra;
        return self;
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::UnitCommand(
            cast_to_bw(tx.unit),
            cast_to_bw(tx.type),
            cast_to_bw(tx.target),
            tx.x,
            tx.y,
            tx.extra);
    }
};
template<>
struct CastFwd<BWAPI::UnitCommand> {
    typedef Cast<BWAPI::UnitCommand, UnitCommand> Type;
};
template<>
struct CastRev<UnitCommand> {
    typedef Cast<BWAPI::UnitCommand, UnitCommand> Type;
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
struct Cast<BWAPI::PlayerType, PlayerType> {
    typedef BWAPI::PlayerType BwType;
    typedef PlayerType        TxType;

    inline static TxType from_bw(BwType bw) {
        return PlayerType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::PlayerType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::PlayerType> {
    typedef Cast<BWAPI::PlayerType, PlayerType> Type;
};
template<>
struct CastRev<PlayerType> {
    typedef Cast<BWAPI::PlayerType, PlayerType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::TechType, TechType> {
    typedef BWAPI::TechType BwType;
    typedef TechType        TxType;

    inline static TxType from_bw(BwType bw) {
        return TechType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::TechType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::TechType> {
    typedef Cast<BWAPI::TechType, TechType> Type;
};
template<>
struct CastRev<TechType> {
    typedef Cast<BWAPI::TechType, TechType> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::WeaponType, WeaponType> {
    typedef BWAPI::WeaponType BwType;
    typedef WeaponType        TxType;

    inline static TxType from_bw(BwType bw) {
        return WeaponType {bw.getID()};
    }
    inline static BwType to_bw(TxType tx) {
        return BWAPI::WeaponType(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::WeaponType> {
    typedef Cast<BWAPI::WeaponType, WeaponType> Type;
};
template<>
struct CastRev<WeaponType> {
    typedef Cast<BWAPI::WeaponType, WeaponType> Type;
};

//----------------------------------------------------

template<>
struct Cast<BWAPI::Key, KeyButton> {
    typedef BWAPI::Key BwType;
    typedef KeyButton  TxType;
    static TxType from_bw(BwType bw) {
        return KeyButton {static_cast<int>(bw)};
    }
    static BwType to_bw(TxType tx) {
        return static_cast<BWAPI::Key>(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::Key> {
    typedef Cast<BWAPI::Key, KeyButton> Type;
};
template<>
struct CastRev<KeyButton> {
    typedef Cast<BWAPI::Key, KeyButton> Type;
};
//----------------------------------------------------

template<>
struct Cast<BWAPI::MouseButton, MouseButton> {
    typedef BWAPI::MouseButton BwType;
    typedef MouseButton  TxType;
    static TxType from_bw(BwType bw) {
        return MouseButton {static_cast<int>(bw)};
    }
    static BwType to_bw(TxType tx) {
        return static_cast<BWAPI::MouseButton>(tx.id);
    }
};
template<>
struct CastFwd<BWAPI::MouseButton> {
    typedef Cast<BWAPI::MouseButton, MouseButton> Type;
};
template<>
struct CastRev<MouseButton> {
    typedef Cast<BWAPI::MouseButton, MouseButton> Type;
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
