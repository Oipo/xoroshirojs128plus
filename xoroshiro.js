var xoroshirojsBinding = require('bindings')('xoroshirojs.node')

exports.seed = function (high, low) {
    return xoroshirojsBinding.seed(high, low);
}

exports.seedWithCurrentTime = function () {
    var ms = (new Date).getTime();
    return xoroshirojsBinding.seed(ms%1000, ms);
}

exports.next = function () {
    return xoroshirojsBinding.next();
}
