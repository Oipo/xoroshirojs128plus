#include <nan.h>
#include "splitmix64.h"
#include "xoroshiro128plus.h"

bool seeded = false;

NAN_METHOD(Seed) {
  if (info.Length() != 2) {
    Nan::ThrowTypeError("Wrong number of arguments, expected 2");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments, expected number");
    return;
  }

  if (!info[1]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments, expected number");
    return;
  }

  uint64_t arg0 = info[0]->Uint32Value();
  uint64_t arg1 = info[1]->Uint32Value();
  uint64_t seed = (arg0 << 32) + arg1;
  uint64_t seed2 = splitmix64_next(seed);

  xoroshiro_seed(seed, seed2);
  seeded = true;

  info.GetReturnValue().Set(true);
}

NAN_METHOD(Next) {
    if (info.Length() != 0) {
        Nan::ThrowTypeError("Wrong number of arguments, expected 0");
        return;
    }

    if (!seeded) {
        Nan::ThrowTypeError("Call Seed first before requesting a value");
        return;
    }

    uint64_t val = xoroshiro_next();
    v8::Local<v8::Array> result = Nan::New<v8::Array>(2);
    Nan::Set(result, 0, Nan::New<v8::Number>((uint32_t)(val >> 32)));
    Nan::Set(result, 1, Nan::New<v8::Number>((uint32_t)val));

    info.GetReturnValue().Set(result);
}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("seed").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(Seed)->GetFunction());
    exports->Set(Nan::New("next").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(Next)->GetFunction());
}

NODE_MODULE(xoroshiro, Init)
