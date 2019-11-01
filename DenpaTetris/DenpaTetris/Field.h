#pragma once
#include"Resource.h"
#
//前方宣言
class Point;
class Cell;

//フィールドクラス
class Field {
public:
	//コンストラクタ
	Field();

	//初期化関数
	void clear();

	//削除関数
	int deleteLine();

	//何だろうこれ？
	/*
	なんだこれ？
	*/
	void fixPiece(const Point pos, const Cell cells[][PieceHeight]);

	//削除した分を動かす
	void shiftLine(int delCount);

	//詰んだかどうか調べる
	bool isStacked()const
	{
		/*

		こ↑こ↓の決め打ち怪しい

		*/
		if (cells_[6][0].getBlock() || cells_[7][0].getBlock()) {
			return true;
		}
		else {
			return false;
		}
	}

	Cell getCell(int x, int y) const
	{
		return cells_[x][y];
	}

private:
	//ブロック配列
	Cell cells_[FieldWidth][FieldHeight];
};