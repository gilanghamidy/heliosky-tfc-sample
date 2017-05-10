/*
 * Post.h
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#ifndef POST_H_
#define POST_H_

#include <string>
#include <vector>

#include "TFC/Core.h"

namespace Heliosky
{
	namespace Model
	{
		struct Post : public TFC::ObjectClass
		{
			int postId;
			std::string date;
			std::string slug;
			std::string type;
			std::string link;
			std::string title;
			std::string excerpt;
			int authorId;

			static std::vector<Post*>* ParseJson(const std::string& jsonData);

			virtual ~Post() { }
		};
	}


}



#endif /* POST_H_ */
