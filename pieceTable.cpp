#include <iostream>
#include "pieceTable.hpp"

_piece::_piece(e_PIECE_TYPE type, uint32_t startIndex, uint32_t size){
	this->type = type;
	this->start = startIndex;
	this->size = size;
}

_piece::~_piece(){
}


_pieceTable::_pieceTable(const std::string &originalBuff){
	this->originalBuffer = originalBuff;
	this->addedBuffer = "";
	insertPiece(ORIGINAL, 0, 0, originalBuff.size());
}

void	_pieceTable::insertPiece(e_PIECE_TYPE type, uint32_t index, uint32_t indexInBuffer, uint32_t size){
    uint32_t	currentPos, pieceIndex, indexOffset;
	
	currentPos = pieceIndex = 0;
	// get which piece have our Text:
	for (pieceIndex = 0; pieceIndex < pieces.size(); pieceIndex++){
		if (index < currentPos + pieces[pieceIndex].size)
			break;
		currentPos += pieces[pieceIndex].size;
	}
	
	indexOffset = index - currentPos;
	// split piece if needed:
	if (indexOffset > 0 && indexOffset < pieces[pieceIndex].size){
		splitPiece(pieceIndex, indexOffset);
		pieceIndex++;
	}
	// add piece;
	_piece newPiece(type, indexInBuffer, size);
	pieces.insert(pieces.begin() + pieceIndex, newPiece);
}

void	_pieceTable::splitPiece(uint32_t pieceIndex, uint32_t splitIndex){
	_piece &piece = pieces[pieceIndex];

	_piece leftPiece(piece.type, piece.start, splitIndex);
	_piece rightPiece(piece.type, piece.start + splitIndex, piece.size - splitIndex);

	pieces.erase(pieces.begin() + pieceIndex);
	pieces.insert(pieces.begin() + pieceIndex, {leftPiece, rightPiece});
}

void	_pieceTable::addText(const std::string &s, uint32_t index){
	uint32_t indexInAdded = addedBuffer.size();
	addedBuffer.append(s);
	insertPiece(ADDED, index, indexInAdded, s.size());
}

void	_pieceTable::debugTable(void){
	std::cout << ">> START DEBUG" << std::endl;
	for (size_t i = 0; i < pieces.size(); i++){
		const char *type = (pieces[i].type == ORIGINAL) ? "ORIGINAL" : "ADDED";
		std::cout << i << " : " << type << " : " << pieces[i].start << " : " << pieces[i].size << std::endl;
	}
	std::cout << ">> END   DEBUG" << std::endl;
}

void	_pieceTable::showText(void){
	for (size_t i = 0; i < pieces.size(); i++){
		std::string *data = &originalBuffer;
		if (pieces[i].type == ADDED)
			data = &addedBuffer;
		std::cout << (*data).substr(pieces[i].start, pieces[i].size);
	}
	std::cout << std::endl;
}

std::string _pieceTable::returnText(){
    std::string result;

    for (size_t i = 0; i < pieces.size(); ++i) {
        const auto &p = pieces[i];
        const std::string &buf = (p.type == ADDED ? addedBuffer : originalBuffer);
        result.append(buf, p.start, p.size);
    }
    return result;
}


void	_pieceTable::removeText(uint32_t index, uint32_t size){

}

_pieceTable::~_pieceTable(){

}
