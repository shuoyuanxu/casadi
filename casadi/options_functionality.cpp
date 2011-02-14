/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "options_functionality.hpp"

#include "stl_vector_tools.hpp"
#include "casadi_exception.hpp"

const char *opt_type_name[] =  { "boolean", "integer", "real", "string", "integervector", "realvector" };

using namespace std;

namespace CasADi{

void OptionsFunctionalityNode::setOption(const string &name, const Option &op){
  // First check if the option exists
  map<string, opt_type>::const_iterator it = allowed_options.find(name);
  if(it == allowed_options.end()){
    stringstream ss;
    ss << "Unknown option: " << name << endl;
    throw CasadiException(ss.str());
  }

  // Save the option
  dictionary_[name] = op;
}
Option OptionsFunctionality::getOption(const string &name) const{
  return (*this)->getOption(name);
}
 
Option OptionsFunctionalityNode::getOption(const string &name) const{

  // Locate the option
  Dictionary::const_iterator it = dictionary_.find(name);

  // Check if found
  if(it == dictionary_.end()){
    stringstream ss;
    ss << "Option: " << name << " has not been set." << endl;
    throw CasadiException(ss.str());
  }
  
  // Return the option
  return Option(it->second);
}

void OptionsFunctionalityNode::addOption(const string &name, const opt_type& type, const Option &def_val){
  allowed_options[name] = type;

  if(!def_val.isNull())
    dictionary_[name] = Option(def_val);

}

void OptionsFunctionalityNode::printOptions(ostream &stream) const{
  // Print allowed options
  stream << "\"Option name\" [type] = value" << endl;
  for(map<string, opt_type>::const_iterator it=allowed_options.begin(); it!=allowed_options.end(); ++it){
    stream << "  \"" << it->first << "\" [" << opt_type_name[it->second] << "] ";
    
    // Check if it is has been set
    Dictionary::const_iterator j=dictionary_.find(it->first);
    if(j==dictionary_.end())
      stream << "(not set)";
    else
      stream << "= " << j->second;
    
    stream << endl;
  }
  stream << endl;
}

bool OptionsFunctionalityNode::hasOption(const string &str) const{
  return allowed_options.find(str) != allowed_options.end();
}

bool OptionsFunctionalityNode::hasSetOption(const string &str) const{
  if(!hasOption(str)) throw CasadiException("OptionsFunctionalityNode::hasSetOption: no such option");
  Dictionary::const_iterator it = dictionary_.find(str);
  return it != dictionary_.end();
}


OptionsFunctionality::OptionsFunctionality(){
}

OptionsFunctionality::~OptionsFunctionality(){
}

OptionsFunctionalityNode* OptionsFunctionality::operator->(){
  return (OptionsFunctionalityNode*)(SharedObject::operator->());
}

const OptionsFunctionalityNode* OptionsFunctionality::operator->() const{
  return (const OptionsFunctionalityNode*)(SharedObject::operator->());
}

OptionsFunctionalityNode::OptionsFunctionalityNode(){  
  addOption("name",            OT_STRING, "unnamed_shared_object"); // name of the object
}

OptionsFunctionalityNode::~OptionsFunctionalityNode(){
}

void OptionsFunctionality::setOption(const string &str, const Option& op){
  (*this)->setOption(str,op);
}

void OptionsFunctionality::setOption(const Dictionary& dict){
  (*this)->setOption(dict);
}

bool OptionsFunctionality::hasOption(const string &str) const{
  return (*this)->hasOption(str);
}

bool OptionsFunctionality::hasSetOption(const string &str) const{
  return (*this)->hasSetOption(str);  
}

void OptionsFunctionality::printOptions(ostream &stream) const{
  (*this)->printOptions(stream);  
}
  
bool OptionsFunctionality::checkNode() const{
  return dynamic_cast<const OptionsFunctionalityNode*>(get());
}

void OptionsFunctionality::copyOptions(const OptionsFunctionality& obj){
  (*this)->copyOptions(obj);
}

const Dictionary& OptionsFunctionality::dictionary() const{
  (*this)->dictionary();
}

const Dictionary& OptionsFunctionalityNode::dictionary() const{
  return dictionary_;
}

void OptionsFunctionalityNode::setOption(const Dictionary& dict){
  for(Dictionary::const_iterator it=dict.begin(); it!=dict.end(); ++it){
    setOption(it->first,it->second);
  }
}

void OptionsFunctionalityNode::copyOptions(const OptionsFunctionality& obj){
  setOption(obj.dictionary());
}

void OptionsFunctionalityNode::repr(std::ostream &stream) const{
  stream << getOption("name").toString();
}


} // namespace CasADi

