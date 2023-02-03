#pragma once
#include <string>
#include "json/value.h"

Json::Value readJSON();

std::string parseJSON(Json::Value messages);