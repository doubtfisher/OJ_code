int my_atoi(string str)
{
	long long ret = 0;
	int  flag = 1;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isspace(str[i]))//判断是否是空白字符串
			continue;
		else if (str[i] == '-')//如果是负数
			flag = -1;
		else if(str[i] == '+')//如果是正数
			flag = 1;
		else if (str[i] == '.')//如果是小数
			break;
		else if (str[i] >= '0' && str[i] <= '9')//如果是正常数
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
