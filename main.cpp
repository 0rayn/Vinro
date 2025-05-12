#include <iostream>
#include "pieceTable.hpp"

int	main(){
	_pieceTable pieceTable("HELLO GUYS");
	pieceTable.debugTable();
	pieceTable.addText("AAA", 2);
	pieceTable.debugTable();
	pieceTable.addText("BBB", 2);
	pieceTable.debugTable();
	pieceTable.showText();
	std::cout << pieceTable.returnText() << std::endl;

}