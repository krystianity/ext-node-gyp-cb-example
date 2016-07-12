#include <node.h>
#include <iostream>
#include <string>

#include "test.h"

using namespace v8;

void RunCallback(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	if (args.Length() < 3) {
		isolate->ThrowException(Exception::TypeError(
			String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	std::string str = "";
	double doub = 0;

	if (args[0]->IsString()) {
		v8::String::Utf8Value utf8Str(args[0]->ToString());
		str = std::string(*utf8Str);
	}

	if (args[1]->IsNumber()) {
		doub = args[1]->NumberValue();
		Test* t = new Test(3.1);
		doub = t->get(doub);
		delete t;
	}

	Local<Number> num = Number::New(isolate, doub);
	Local<Function> cb = Local<Function>::Cast(args[2]);

	const unsigned argc = 4;
	Local<Value> argv[argc] = {
	  String::NewFromUtf8(isolate, "hello world"),
	  String::NewFromUtf8(isolate, "people say"),
	  String::NewFromUtf8(isolate, str.c_str()),
	  num
	};

	cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
}

void Init(Handle<Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(module, "exports", RunCallback);
}

NODE_MODULE(addon, Init)
