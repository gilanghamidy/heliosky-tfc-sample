/*
 * PostWebService.h
 *
 *  Created on: Jul 15, 2016
 *      Author: gilang
 */

#ifndef POSTWEBSERVICE_H_
#define POSTWEBSERVICE_H_

#include <vector>
#include "TFC/Net/REST.h"
#include "Model/Post.h"

// Namespace shortcut. Similar with Java's import
using Post = Heliosky::Model::Post;

namespace Heliosky
{
	namespace WebService
	{
		class PostWebService : public TFC::Net::RESTServiceBase<std::vector<Post*>>
		{
		public:
			PostWebService();
			virtual ~PostWebService();

			// Override OnProcessResponse method to process the response string and return the processed data
			virtual std::vector<Post*>* OnProcessResponse(int httpCode, const std::string& responseStr, int& errorCode, std::string& errorMessage);

			// Declare parameter of the web service
			// You can declare parameter either as a query string, header, or post data
			// The consumer of this class can set the value before making request
			// The framework will handle the rest
			Parameter<TFC::Net::ParameterType::Query, std::string> Context;

			Parameter<TFC::Net::ParameterType::Query, int> PerPage;
		};
	}
}



#endif /* POSTWEBSERVICE_H_ */
