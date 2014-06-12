


typedef struct tagSBT
{
	struct tagSBT *pstLC;
	SINT32	nVal;
	struct tagSBT *pstRC;
} SBTree;

SINT32 InsertNode ( SBTree **ppstNode, SINT32 nVal )
{
	/* Include code to insert a node */
	SBTree *temp = NULL;
	
	if (*ppstNode == NULL) {
		temp = (SBTree *) malloc(sizeof(SBTree));
		temp->nVal = nVal;
		temp->pstLC = NULL;
		temp->pstRC = NULL;
		*ppstNode = temp;
		return 0;
	}
	
	if ( nVal < (*ppstNode)->nVal)
		InsertNode(&(*ppstNode)->pstLC, nVal );
	else
		InsertNode(&(*ppstNode)->pstRC, nVal );

	return 0;
}

SINT32 DeleteNode ( SBTree **pstNode, SINT32 nVal )
{
	SBTree *tmp = NULL , *par = NULL, *next = NULL;
	tmp = *pstNode;
	par = *pstNode;

	/* Include code to delete any node */
	//base case
	if (tmp == NULL)
		return 0;

	while (tmp != NULL) {
		if (tmp->nVal == nVal)
			break;
		
		par = tmp;
		if (nVal > tmp->nVal)
			tmp = tmp->pstRC;
		else if (nVal < tmp->nVal)
			tmp = tmp->pstLC;
	}

	printf("par - %d node - %d \n", par->nVal, tmp->nVal);

	/*node to be deleted has both  left or right node*/
	if (tmp->pstLC != NULL && tmp->pstRC != NULL) {
		next = tmp->pstRC;
		par = tmp;
		while (next->pstLC != NULL) {
			par = next;
			next = next->pstLC;
		}

		tmp->nVal = next->nVal;
		tmp = next;
	}

	/*node to be deleted is a leaf, no  left or right node*/
	if (tmp->pstLC == NULL && tmp->pstRC == NULL) {
		if (par->pstLC == tmp)
			par->pstLC = NULL;
		else
			par->pstRC = NULL;

	} else if (tmp->pstLC == NULL && tmp->pstRC != NULL) {				/* either left or right node of tmp is null */
		if (par->pstLC == tmp)
			par->pstLC = tmp->pstRC;
		else
			par->pstRC = tmp->pstRC;
				
	} else if (tmp->pstLC != NULL && tmp->pstRC == NULL) {
		if (par->pstRC == tmp)
			par->pstRC = tmp->pstLC;
		else
			par->pstLC = tmp->pstLC;
		
	}
	
	free(tmp);

	return 0; 
}

SINT32 PrintSortedOrder ( SBTree *pstNode )
{
	/* Include code to print the tree in sorted order */
	if ( pstNode != NULL) {
		PrintSortedOrder(pstNode->pstLC);
		printf("%d\n", pstNode->nVal);
		PrintSortedOrder(pstNode->pstRC);
	}
	return 0;
}

SINT32 PrintPostOrder ( SBTree *pstNode )
{
	/* Include code to print the tree in Post order */
	if ( pstNode != NULL) {
		PrintPostOrder(pstNode->pstLC);
		PrintPostOrder(pstNode->pstRC);
		printf("%d\n", pstNode->nVal);
	}
	return 0;
}

UINT32 height ( SBTree *pstNode )
{
	SBTree *tmp = pstNode;
	UINT32 h = 0;
	UINT32 lt = 0;
	UINT32 rt = 0;

	if (tmp == NULL)
		return 1;
	
	while (tmp->pstLC != NULL || tmp->pstRC != NULL ){
		lt++;
		if (tmp->pstLC == NULL)
			tmp = tmp->pstRC;
		else
			tmp = tmp->pstLC;
	}

	tmp = pstNode;

	while (tmp->pstLC != NULL || tmp->pstRC != NULL ){
		rt++;
		if (tmp->pstRC == NULL)
			tmp = tmp->pstLC;
		else
			tmp = tmp->pstRC;
	}


	printf(" lt = %d rt = %d \n", lt, rt);
	return lt;
}
	

void TestBSTree ( void )
{
	SBTree	*pstRoot = NULL;
	
	PRINT_INFO ( ( "\nTest_BSTree\n" ) );

	InsertNode ( &pstRoot, 100 );
	InsertNode ( &pstRoot, 50 );
	InsertNode ( &pstRoot, 200 );
	InsertNode ( &pstRoot, 250 );
	InsertNode ( &pstRoot, 30 );
	InsertNode ( &pstRoot, 75 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	DeleteNode ( &pstRoot, 30 );

	DeleteNode ( &pstRoot, 75 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	InsertNode ( &pstRoot, 30 );
	InsertNode ( &pstRoot, 75 );

	InsertNode ( &pstRoot, 65 );
	InsertNode ( &pstRoot, 85 );
	
	InsertNode ( &pstRoot, 15 );
	InsertNode ( &pstRoot, 35 );	

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	DeleteNode ( &pstRoot, 50 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	DeleteNode ( &pstRoot, 75 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	DeleteNode ( &pstRoot, 100 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	DeleteNode ( &pstRoot, 30 );

	PRINT_INFO ( ( "\nSorted Order Print.......\n" ) );
	PrintSortedOrder ( pstRoot );

	PRINT_INFO ( ( "\nPostOrder Print.......\n" ) );
	PrintPostOrder ( pstRoot );

	PRINT_INFO ( ( "\n.......\n" ) );

	height(pstRoot);
}
