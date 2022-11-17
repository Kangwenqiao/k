int Location(vector<VNode*>::iterator start , vector<VNode*>::iterator end , char a)
{
	
	int i=0;
	for (; start != end; start++,i++)
	{
		VNode* d = *start;
		if (d->data == a)
		{
			return i;
		}
	}
	exit(1);
}