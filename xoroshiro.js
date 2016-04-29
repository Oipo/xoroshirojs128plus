var xoroshirojsBinding = require('bindings')('xoroshirojs.node')

exports.seed = function (high, low) {
    return xoroshirojsBinding.seed(high, low);
}

exports.next = function () {
    return xoroshirojsBinding.next();
}
