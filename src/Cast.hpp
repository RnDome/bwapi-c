#pragma once

#include <assert.h>

template <class Out, class In>
Out safe_cast(In in) {
    assert(in);
    return reinterpret_cast<Out>(in);
}
