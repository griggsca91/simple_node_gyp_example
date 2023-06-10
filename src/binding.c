#include <node_api.h>

int add_two(int);

napi_value AddNotTwo(napi_env env, napi_callback_info info) {
  napi_value result;
  napi_status status;

  size_t argc = 1;
  napi_value argv[1];

  int64_t value;

  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create string");
    return NULL;
  }

  status = napi_get_value_int64(env, argv[0], &value);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create string");
    return NULL;
  }

  int endValue = add_two(value);

  status = napi_create_int64(env, endValue, &result);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create string");
    return NULL;
  }
  return result;
}

napi_value HelloWorld(napi_env env, napi_callback_info info) {
  napi_value result;
  napi_status status;

  const char* message = "Hello, World!";

  status = napi_create_string_utf8(env, message, NAPI_AUTO_LENGTH, &result);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create string");
    return NULL;
  }

  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;
  napi_value addNotTwoFn;

  status = napi_create_function(env, NULL, 0, HelloWorld, NULL, &fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create function");
    return NULL;
  }

  status = napi_create_function(env, NULL, 0, AddNotTwo, NULL, &addNotTwoFn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create function");
    return NULL;
  }

  status = napi_set_named_property(env, exports, "helloWorld", fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to set named property");
    return NULL;
  }

  status = napi_set_named_property(env, exports, "addNotTwo", addNotTwoFn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to set named property");
    return NULL;
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)

