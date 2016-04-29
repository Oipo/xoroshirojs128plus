var xoroshirojs = require('../xoroshiro')
var chai = require('chai');

chai.expect(xoroshirojs).to.not.be.undefined;

chai.expect(xoroshirojs.seed).to.throw("Wrong arguments, expected number");
chai.expect(xoroshirojs.next).to.throw("Call Seed first before requesting a value");

var ret = xoroshirojs.seed(10, 11)

chai.expect(ret).to.equal(true)

for (var i = 0; i < 5; i++) {
    ret = xoroshirojs.next()
    console.log(ret)
}
