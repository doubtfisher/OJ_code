int my_atoi(string str)
{
	long long ret = 0;
	int  flag = 1;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isspace(str[i]))//�ж��Ƿ��ǿհ��ַ���
			continue;
		else if (str[i] == '-')//����Ǹ���
			flag = -1;
		else if(str[i] == '+')//���������
			flag = 1;
		else if (str[i] == '.')//�����С��
			break;
		else if (str[i] >= '0' && str[i] <= '9')//�����������
		{
			int num = str[i] - '0';
			ret = ret * 10 + num*flag;
			if ((flag == 1 && ret > 0xffffffff) || (flag == -1 && ret < (signed int)0x80000000))
			{
				return 0;
			}
		}
		else
			return 0;
	}
	return ret;
}
