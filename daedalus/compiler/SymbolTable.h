/*
 * Copyright (C) 2016 hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef Daedalus_SymbolTable
#define Daedalus_SymbolTable
#include <limits>
#include <unordered_map>
#include <daedalus/compiler/Symbol.h>
namespace Daedalus {
struct Scope {
	std::vector<Variable> variables;

	// daedalus doesn't support non-top-level class/func,
	// but interpreter doesn't care about that
	std::vector<Function> functions;
	std::vector<Class>    classes;

	std::vector<Instance>  instances;
	std::vector<Prototype> prototypes;
};


struct SymbolTable {
	SymbolTable();

	SymbolRef getSymbol(std::string name);
	Scope*    getScope(SymbolRef ref);
	Symbol*   getSymbol(SymbolRef ref);

	unsigned pushScope();
	unsigned currentScope();
	void popScope();

	enum InsertResult {
		Success,
		AlreadyDefined,
		NotAllowedHere,
	};

	SymbolRef insertVariable(Variable&& var);
	SymbolRef insertClass(Class&& type);
	SymbolRef insertFunction(Function&& func);
	SymbolRef insertInstance(Instance&& func);
	SymbolRef insertPrototype(Prototype&& func);

private:
	using SymbolMap = std::unordered_map<std::string, SymbolRef>;

	SymbolMap table;

	void saveSymbol(std::string name);
	void insertSymbol(std::string name, SymbolRef ref);

	using Entry = std::pair<std::string, SymbolRef>;
	using EntryList = std::vector<Entry>;
	std::vector<EntryList> tableDeltas;

	std::vector<Scope> scopes;
	std::vector<unsigned> scopeStack;
};
} // namespace daedalus
#endif//Daedalus_SymbolTable
