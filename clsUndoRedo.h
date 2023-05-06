#pragma once
#include "clsMyStack.h"

class clsUndoRedo
{

private :

	clsMyStack<string> _stk_to_undo;
	clsMyStack<string> _stk_to_redo;


public :

	clsUndoRedo() {
		_stk_to_undo.push("");
	}

	void set(string value) {
		_stk_to_undo.push(value);
		_stk_to_redo.clear();
	}

	string get() {
		return (_stk_to_undo.front());
	}

	bool undo() {

		if (_stk_to_undo.size() <= 1)
			return false;

		_stk_to_redo.push(_stk_to_undo.front());
		_stk_to_undo.pop();
		return true;
	}

	bool redo() {

		if (!_stk_to_redo.size())
			return false;

		_stk_to_undo.push(_stk_to_redo.front());
		_stk_to_redo.pop();
		return true;
	}

	__declspec(property(get = get, put = set)) string value;
};

