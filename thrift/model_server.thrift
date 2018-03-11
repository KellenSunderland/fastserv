/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


// Set namespaces in languages that support it.
namespace cl fastserv
namespace cpp fastserv
namespace d fastserv
namespace dart fastserv
namespace java fastserv
namespace php fastserv
namespace perl fastserv
namespace haxe fastserv
namespace netcore fastserv

service ModelServer {
    map<i32, double> infer(1:binary image)
}