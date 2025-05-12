#pragma once
#include <vector>


typedef enum {
	ORIGINAL,
	ADDED
}e_PIECE_TYPE;

class _piece {
	public:
		e_PIECE_TYPE	type;
		uint32_t		start;
		uint32_t		size;
	public:
		_piece(e_PIECE_TYPE tpye, uint32_t startIndex, uint32_t size);
		~_piece();
};


class _pieceTable {
	private:
		std::string	originalBuffer;
		std::string	addedBuffer;
		std::vector<_piece>		pieces;
	public:
		_pieceTable(const std::string &originalBuff);
		void	insertPiece(e_PIECE_TYPE type, uint32_t index, uint32_t indexInBuffer, uint32_t size);
		void	splitPiece(uint32_t pieceIndex, uint32_t splitIndex);
		void	addText(const std::string &s, uint32_t index);
		void	removeText(uint32_t index, uint32_t size);
	
		void		debugTable(void);
		void		showText(void);
		std::string	returnText(void);
		~_pieceTable();
};
