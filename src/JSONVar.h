/*
 * \file
 * ID:            $Id: $
 * Revision:      $Revision: $
 * Checked in by: $Author: $
 * Last modified: $Date: $
 */

 /*
  This file is part of the Arduino JSON library.
  Copyright (c) 2019 Arduino SA. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _JSON_VAR_H_
#define _JSON_VAR_H_

#include <Arduino.h>

struct cJSON;

#define typeof typeof_
#define null nullptr

class JSONVar : public Printable {
public:
	JSONVar();
	JSONVar( const bool& b );
	JSONVar( const int& i );
	JSONVar( const long& l );
	JSONVar( const uint8_t& u8Value );
	JSONVar( const uint16_t& u16Value );
	JSONVar( const unsigned long& ul );
	JSONVar( const double& d );
	JSONVar( const char* s );
	JSONVar( const String& s );
	JSONVar( const JSONVar& v );
#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
	JSONVar( JSONVar&& v );
#endif
	JSONVar( std::nullptr_t );
	virtual ~JSONVar();

	virtual size_t printTo( Print& p ) const;

	operator bool() const;
	operator int() const;
	operator uint8_t() const;
	operator uint16_t() const;
	operator unsigned int() const;
	operator long() const;
	operator double() const;
	operator const char*( ) const;
	operator String() const;

  JSONVar& operator=(const JSONVar& v);
#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
  JSONVar& operator=(JSONVar&& v);
#endif
  JSONVar& operator=(const bool& b);
  JSONVar& operator=( const int& i);
  JSONVar& operator=( const long& l);
  JSONVar& operator=( const uint8_t& u8Value );
  JSONVar& operator=( const uint16_t& u16Value );
  JSONVar& operator=( const unsigned long& ul);
  JSONVar& operator=( const double& d);
  JSONVar& operator=(const char* s);
  JSONVar& operator=(const String& s);
  JSONVar& operator=(std::nullptr_t);

  bool operator==(const JSONVar& v) const;
  bool operator==(std::nullptr_t) const;

  JSONVar operator[](const char* key);
  JSONVar operator[]( const char* key ) const;
  JSONVar operator[](const String& key) const;
  JSONVar operator[](int index);
  JSONVar operator[](int index) const;
  JSONVar operator[](const JSONVar& key) const;

  int length() const;
  JSONVar keys() const;
  bool hasOwnProperty(const char* key) const;
  bool hasOwnProperty(const String& key) const;

  static JSONVar parse(const char* s);
  static JSONVar parse(const String& s);
  static String stringify(const JSONVar& value);
  static String typeof_(const JSONVar& value);

private:
  JSONVar(struct cJSON* json, struct cJSON* parent);

  void replaceJson(struct cJSON* json);

private:
  struct cJSON* _json;
  struct cJSON* _parent;
};

extern JSONVar undefined;

#endif
