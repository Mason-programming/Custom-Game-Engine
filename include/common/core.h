#pragma once
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>
#define FMT_HEADER_ONLY
#define SPDLOG_FMT_EXTERNAL

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

// import, export
#ifdef EMPY_EXPORT
#ifdef _MSC_VER
#define EMPY_API__declspec(dllexport)
#else
#define EMPY_API
_attribute__((visibility("default")))
#endif
#else

#ifdef MSC VER
#define EMPY_API__declspec(dilimport)
#else
#define EMPY_API

#endif
#endif