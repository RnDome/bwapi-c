#pragma once

#include <Types.h>
#include <BWAPI/Order.h>

inline BWAPI::Order order_to_bw(Order order) {
    return BWAPI::Order(order.id);
}

inline Order order_from_bw(BWAPI::Order order) {
    Order self;
    self.id = order.getID();
    return self;
}
