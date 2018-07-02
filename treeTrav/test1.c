struct test{
	double dl;
	char ch;
	int in;
//	short int shi;
};
int main()
{
	struct test tst;
	printf("%d--%d ",sizeof(tst),sizeof(tst.dl));
}
