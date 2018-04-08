#include "StdAfx.h"
#include "TicTacToeAI.h"

/**
	�� �� : TicTacToeAI(GameBoard board)
	�� �� : ���� �������� �Ѱܹ޴� ������ �Լ�
*/
TicTacToeAI::TicTacToeAI(GameBoard board)
{
	tttBoard = board;
	root = new Node;
	InitNode(root, 0);
	LAlevel = tttBoard.startLevel;

};

/**
	�� �� : InitNode(Node* node, int inDepth)
	�� �� : ����� ��带 ����, eval�� ������ �ʱ�ȭ
*/
void TicTacToeAI::InitNode(Node* node, int inDepth)
{
	node->depth = inDepth;
	node->eval = 0;
	node->childCnt = 0;

	for(int i=0; i<16; i++)
		node->next[i] = NULL;
};

/**
	�� �� : GetRootNode()
	�� �� : ��Ʈ��带 ��ȯ
*/
Node* TicTacToeAI::GetRootNode()
{
	return root;
};

/**
	�� �� : GetBestMove()
	�� �� : ������ ��ǥ�� Minimax �˰����� ���� ����
*/
void TicTacToeAI::GetBestMove()
{
	Position iList[16];				/* ���� �����ǿ��� ���� �� �ִ� ��ǥ ����, ��ġ ���� */
	int	bestValue = -10000;			/* besteval �� ���� */
	int	possible = 0;				/* ������ ���� ���� ���� */
		
	possible = GetPossibleMove(iList);	/*���� ������ �� ��ǥ, ���� ���� */
	for( int i = 0; i < possible; i++ )				/* ������ �� ��ŭ Minimax �˰����� ����Ͽ� ���� ��� */
	{
		root->next[i] = new Node;					/* ���ο� ��� ���� */
		InitNode(root->next[i], (root->depth)+1);	/* ��� �ʱ�ȭ */
		tttBoard.DoMove(iList[i].x , iList[i].y);	/* ������ ���� �� */
		int newValue = Minimize(root->next[i]);		/* Min�Լ�ȣ��� ���� ���ؼ� */
		root->next[i]->eval = newValue;				/* ��忡 ���� */
		tttBoard.UndoMove();						/* �ξ��� ���� ���� */

		if( newValue > bestValue )		/* ���� eval���� best������ ũ�ٸ� */
		{
			bestValue = newValue;		/* ���� �����ϰ� �ش� �������� ���� */
			bestX = iList[i].x;
			bestY = iList[i].y;
			root->eval = bestValue;		/* ��忡 ���� ���� */
		}
	}
	root->childCnt = possible;			/* �ڽ� ��� ���� ���� */
};

/**
	�� �� : Minimize(struct treeNode* root)
	�� �� : ���� �ڽ� ���� eval���߿��� ���� ���� ������ �����ϴ� �Լ�
*/
int TicTacToeAI::Minimize(struct treeNode* root)
{
	Position iList[16];			/* ���� �����ǿ��� ���� �� �ִ� ��ǥ ����, ��ġ ���� */
	int	possible = 0;			/* �Ѽ��ִ� ���� ���� ���� */
	int	bestValue = 10000;		/* besteval �� ���� */

	possible = GetPossibleMove(iList); /*���� ������ �� ��ǥ, ���� ���� */
		
	if( possible == 0 || CheckEnd() || root->depth == LAlevel ) /* �����Ѽ� ���ų�, ��������� eval ���� ����Ͽ� ���� */
	{
		return EvaluateBoard(root);
	}		

	for( int i = 0; i < possible; i++ ) /* ������ �� ��ŭ Minimax �˰����� ����Ͽ� ���� ��� */
	{
		root->next[i] = new Node;					/* ��� ���� �� �ʱ�ȭ */
		InitNode(root->next[i], root->depth+1);

		tttBoard.DoMove(iList[i].x , iList[i].y);	/* ������ ���� �� */
		int newValue = Maximize(root->next[i]);		/* Max�Լ�ȣ��� ���� ���ؼ� */
		root->next[i]->eval = newValue;				/* ��忡 ���� */
		tttBoard.UndoMove();						/* �ξ��� ���� ���� */

		if( newValue < bestValue )	/* ���� eval���� best������ �۴ٸ� */
		{				
			bestValue = newValue;	/* ���� �����ϰ� �ش簪���� ��尪�� ���� */
			root->eval = bestValue;
		}
	}
	root->childCnt = possible;		/* �ڽ� ��尳�� ���� */
	return bestValue;				/* bestValue �� ��ȯ */
};

/**
	�� �� : Maximize(struct treeNode* root)
	�� �� : ���� �ڽ� ���� eval���߿��� ���� ū ������ �����ϴ� �Լ�
*/
int TicTacToeAI::Maximize(struct treeNode* root)
{
	Position iList[16];			/* ���� �����ǿ��� ���� �� �ִ� ��ǥ ����, ��ġ ���� */
	int	bestValue = -10000;		/* besteval �� ���� */
	int	possible;				/* �Ѽ��ִ� ���� ���� ���� */
		
	possible = GetPossibleMove(iList);	/*���� ������ �� ��ǥ, ���� ���� */
		
	if( possible == 0 || CheckEnd() || root->depth == LAlevel )	/* �����Ѽ� ���ų�, ��������� eval ���� ����Ͽ� ���� */
	{
		return EvaluateBoard(root);
	}		

	for( int i = 0; i < possible; i++ )	/* ������ �� ��ŭ Minimax �˰����� ����Ͽ� ���� ��� */
	{
		root->next[i] = new Node;					/* ��� ���� �� �ʱ�ȭ */
		InitNode(root->next[i], root->depth+1);

		tttBoard.DoMove(iList[i].x , iList[i].y);	/* ������ ���� �� */		
		int newValue = Minimize(root->next[i]);		/* Min�Լ�ȣ��� ���� ���ؼ� */
		root->next[i]->eval = newValue;				/* ��忡 ���� */
		tttBoard.UndoMove();						/* �ξ��� ���� ���� */

		if( newValue > bestValue )				/* ���� eval���� best������ ũ�ٸ� */
		{				
			bestValue = newValue;				/* ���� �����ϰ� �ش簪���� ��尪�� ���� */
			root->eval = bestValue;	
		}		
	}
	root->childCnt = possible;					/* �ڽ� ��尳�� ���� */
	return bestValue;							/* bestValue �� ��ȯ */
};

/**
	�� �� :	CheckSymmetric(GameBoard preBoard, GameBoard newBoard)
	�� �� : �Լ� ��Ī���� �˻��ϴ� �Լ�
*/
int TicTacToeAI::CheckSymmetric(GameBoard preBoard, GameBoard newBoard)
{
	int i, j, k, check = 0;

	char newboard[4][4];	/* �˻� ��� �������� ������ ���� */
	char copy[4][4];		
	char temp[4][4];

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
		{
			copy[i][j] = preBoard.board[i][j];		/* ���� �������� ���� */
			newboard[i][j] = newBoard.board[i][j];	/* �˻� ��� �������� ���� */
		}

	 /* copy �������� �������� ȸ��, �� 3�� ȸ�� */
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)            
			for(k=0; k<4; k++)
				temp[j][k]=copy[j][k];

		for(j=0; j<4; j++)       
			for(k=0; k<4; k++)
				copy[3-k][j]=temp[j][k];
			
		if(CheckSameBoard(copy, newboard))	/* �ѹ� ȸ���Ҷ����� ������ �˻� */
			return 1;						/* ������ 1 ��ȯ */
	}

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			temp[i][j]=copy[i][j];
	
	 /* copy �������� �¿�� ��Ī */
	for(i=0;i<4;i++)
	{
		copy[i][0] = temp[i][3];
		copy[i][3] = temp[i][0];
		copy[i][1] = temp[i][2];
		copy[i][2] = temp[i][1];
	}

	if(CheckSameBoard(copy, newboard))	/* ��Ī�� ������ �˻� */
		return 1;						/* ������ 1 ��ȯ */
	

	/* copy �������� �������� ȸ��, �� 3�� ȸ�� */
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)               
			for(k=0; k<4; k++)
				temp[j][k]=copy[j][k];

		for(j=0; j<4; j++)
			for(k=0; k<4; k++)
				copy[3-k][j]=temp[j][k];
			
		if(CheckSameBoard(copy, newboard))	/* �ѹ� ȸ���Ҷ����� ������ �˻� */
			return 1;						/* ������ 1 ��ȯ */
	}
	return 0;
};

/**
	�� �� : CheckSameBoard(char (*board1)[3], char (*board2)[3])
	�� �� :	���� �����ǰ� �˻��� �������� �޾ƿͼ� ��ġ�ϴ��� ���� �˻�
*/
int TicTacToeAI::CheckSameBoard(char (*board1)[4], char (*board2)[4])
{
	int i, j;
	int count = 0;

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			if(board1[i][j] == board2[i][j])
				count++;

	if(count == 16)	
		return 1;    /* ������ 1 ��ȯ */
	else			
		return 0;    /* �ٸ��� 0 ��ȯ */
};

/**
	�� �� : GetPossibleMove(Position* iList)
	�� �� : ���� �����ǿ��� ���� �Ѷ� �Ѽ��ִ� ���� ��ǥ��, �� ������ ����
*/
int TicTacToeAI::GetPossibleMove(Position* iList)
{
	int	iNum = 0;	/* ������ �� ���� ������ ���� */
	int	check = 0;	/* ��Ī�� �˻� ���� */
	int k=0;

	GameBoard tempBoard = tttBoard;	/* ������ ���� */
		
	for(int i=0; i<4; i++ )
	{
		for(int j=0; j<4; j++)
		{
			if( tttBoard.board[i][j] == ' ' )
			{
				check = 0;
				for(int k=0; k<iNum; k++)
				{
					tttBoard.DoMove(i, j);
					tempBoard.DoMove(iList[k].x, iList[k].y);
					check =	CheckSymmetric(tempBoard, tttBoard);	/* ��Ī�� �˻� */
					tempBoard.UndoMove();
					tttBoard.UndoMove();
					if(check == 1)		/* ��Ī�ȴٸ� ��ŵ */
						break;
				}
				
				if(!check)				/* �ƴ϶��, */
				{
					iList[iNum].x = i;		/* ���� x��ǥ, y��ǥ ���� */
					iList[iNum].y = j;
					iNum++;					/* ���� ���� */				
				}
			}
		}
	}			
	return iNum;	/* ���� ��ȯ */
};

/**
	�� �� : CheckEnd()
	�� �� : ���� ������ ���¸� ���� �ϴ� �Լ� 
*/
int TicTacToeAI::CheckEnd()
{
	tttBoard.CheckState();		
	if( tttBoard.state != GameBoard::STATE_PLAY )
	{
		tttBoard.state = GameBoard::STATE_PLAY;
		return 1;
	}
	else
		return 0;
}

/**
	�� �� : EvaluateBoard()
	�� �� : �ش� �����ǿ��� �̱���ִ� ������ �˻��ؼ� �򰡰��� ��ȯ���ִ� �Լ� 
*/
int TicTacToeAI::EvaluateBoard(struct treeNode* root)
{
	char calBoard[4][4];
	int eval = 0, k = 0;		
	int comA = 0, comB = 0;

	tttBoard.CheckState();
	if( tttBoard.state != GameBoard::STATE_PLAY )
	{
		if(tttBoard.state == GameBoard::STATE_WINA)
		{
			if(this->criterion == 'X')
				eval = 100 - root->depth;
			else
				eval = -100 + root->depth;
			tttBoard.state = GameBoard::STATE_PLAY;

			return eval;
		}
		else if(tttBoard.state == GameBoard::STATE_WINB)
		{
			if(this->criterion == 'X')
				eval = -100 + root->depth;
			else
				eval = 100 - root->depth;
			tttBoard.state = GameBoard::STATE_PLAY;

			return eval;
		}		
	}
	
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			calBoard[i][j] = tttBoard.board[i][j];

	/* ���� 4��, ���� 4���� ���� X, O�� �̱���ִ� ���� ��� */
	for(int i=0;i<4;i++)
	{
		if( (calBoard[i][0]=='X' || calBoard[i][0]==' ') && 
			(calBoard[i][1]=='X' || calBoard[i][1]==' ') && 
			(calBoard[i][2]=='X' || calBoard[i][2]==' ') &&
			(calBoard[i][3]=='X' || calBoard[i][3]==' '))
			comA++;
		if( (calBoard[i][0]=='O' || calBoard[i][0]==' ') && 
			(calBoard[i][1]=='O' || calBoard[i][1]==' ') && 
			(calBoard[i][2]=='O' || calBoard[i][2]==' ') &&
			(calBoard[i][3]=='O' || calBoard[i][3]==' '))
			comB++;
		if( (calBoard[0][i]=='X' || calBoard[0][i]==' ') && 
			(calBoard[1][i]=='X' || calBoard[1][i]==' ') && 
			(calBoard[2][i]=='X' || calBoard[2][i]==' ') &&
			(calBoard[3][i]=='X' || calBoard[3][i]==' '))
			comA++;
		if( (calBoard[0][i]=='O' || calBoard[0][i]==' ') && 
			(calBoard[1][i]=='O' || calBoard[1][i]==' ') && 
			(calBoard[2][i]=='O' || calBoard[2][i]==' ') &&
			(calBoard[3][i]=='O' || calBoard[3][i]==' '))
			comB++;
	}
	
	/* ����, ������ �밢������ �̱���ִ� ���� ��� */
	if( (calBoard[0][0]=='X' || calBoard[0][0]==' ') && 
		(calBoard[1][1]=='X' || calBoard[1][1]==' ') && 
		(calBoard[2][2]=='X' || calBoard[2][2]==' ') &&
		(calBoard[3][3]=='X' || calBoard[3][3]==' '))
		comA++;
	if( (calBoard[0][0]=='O' || calBoard[0][0]==' ') && 
		(calBoard[1][1]=='O' || calBoard[1][1]==' ') && 
		(calBoard[2][2]=='O' || calBoard[2][2]==' ') &&
		(calBoard[3][3]=='O' || calBoard[3][3]==' '))
		comB++;

	if( (calBoard[0][3]=='X' || calBoard[0][3]==' ') && 
		(calBoard[1][2]=='X' || calBoard[1][2]==' ') && 
		(calBoard[2][1]=='X' || calBoard[2][1]==' ') &&
		(calBoard[3][0]=='X' || calBoard[3][0]==' '))
		comA++;
	if( (calBoard[0][3]=='O' || calBoard[0][3]==' ') && 
		(calBoard[1][2]=='O' || calBoard[1][2]==' ') && 
		(calBoard[2][1]=='O' || calBoard[2][1]==' ') &&
		(calBoard[3][0]=='O' || calBoard[3][0]==' '))
		comB++;

	/* ���� AI������ ��ǻ�� A���� B������ ���� �̱���ִ� ���� ����ؼ� ��ȯ */

	eval = comA-comB;
	return eval;
};