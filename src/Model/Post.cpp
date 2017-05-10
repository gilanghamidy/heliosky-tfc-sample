/*
 * Post.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: gilang
 */

#include "Heliosky.h"
#include "Model/Post.h"
#include <exception>
#include <sstream>

#include "rapidjson/document.h"
#include "rapidjson/error/en.h"

Heliosky::Model::Post* ParsePostItem(const rapidjson::Value& val)
{
	auto post = new Heliosky::Model::Post();

	post->authorId = val["id"].GetInt();
	post->date = val["date"].GetString();
	post->slug = val["slug"].GetString();
	post->type = val["type"].GetString();
	post->link = val["link"].GetString();
	post->title = val["title"]["rendered"].GetString();
	post->excerpt = val["excerpt"]["rendered"].GetString();
	post->authorId = val["author"].GetInt();

	return post;
}

std::vector<Heliosky::Model::Post*>* Heliosky::Model::Post::ParseJson(const std::string& jsonData)
{
	rapidjson::StringStream str(jsonData.c_str());
	rapidjson::Document document;

	// First three bytes are Byte-order-mark of UTF8
	// So we skip parsing starts from bytes no. 4
	rapidjson::ParseResult res = document.Parse(&jsonData.c_str()[3]);

	if(document.HasParseError())
		throw HelioskyException("Error parsing the document");

	// Create return object
	auto returnList = new std::vector<Heliosky::Model::Post*>();

	rapidjson::SizeType totalItems = document.Size();

	for(rapidjson::SizeType i = 0; i < totalItems; i++)
	{
		returnList->push_back(ParsePostItem(document[i]));
	}

	return returnList;
}
