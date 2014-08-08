/*
 * Copyright 2013+ Ruslan Nigmatullin <euroelessar@yandex.ru>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "stream_p.hpp"

namespace ioremap {
namespace thevoid {

reply_stream::reply_stream()
{
}

reply_stream::~reply_stream()
{
}

void reply_stream::virtual_hook(reply_stream::reply_stream_hook id, void *data)
{
	(void) id;
	(void) data;
}

base_request_stream::base_request_stream()
{
}

base_request_stream::~base_request_stream()
{
}

void base_request_stream::initialize(const std::shared_ptr<reply_stream> &reply)
{
	m_reply = reply;
	m_logger.reset(new swarm::logger(reply->create_logger()));
}

void base_request_stream::virtual_hook(base_request_stream::request_stream_hook id, void *data)
{
	(void) id;
	(void) data;
}

} // namespace thevoid
} // namespace ioremap
