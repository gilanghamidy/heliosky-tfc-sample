/*
 * PostWebService.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: gilang
 */

#include "WebService/PostWebService.h"
#include <iostream>
#include <fstream>

#define URL_POST "http://heliosky.com/wp-json/wp/v2/posts"

Heliosky::WebService::PostWebService::PostWebService() :
	// Call base class constructor. Pass the URL and HTTP request mode (GET, POST, etc)
	TFC::Net::RESTServiceBase<std::vector<Post*>>(URL_POST, TFC::Net::HTTPMode::Get),

	// Initialize the parameter declaration. First parameter always this
	// second parameter is the key for the parameter to be sent via HTTP
	Context(this, "context"),
	PerPage(this, "per_page")
{
	// We can set the parameter default here in the constructor
	this->Context = "embed";
}

Heliosky::WebService::PostWebService::~PostWebService()
{
	// Destructor
}

std::vector<Post*>* Heliosky::WebService::PostWebService::OnProcessResponse(
		int httpCode, const std::string& responseStr, int& errorCode,
		std::string& errorMessage)
{
	// If it is not HTTP OK, return null
	if(httpCode != 200)
		return nullptr;

	// Parse the JSON
	try
	{
		return Model::Post::ParseJson(responseStr);
	}
	catch(std::exception& err)
	{
		// If error just return null
		return nullptr;
	}
}
