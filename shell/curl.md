## curl

	//curl功能似乎超级多，但是由于只是满足别人一个小要求暂时先看到这里。
	//回头似乎可以继续看搞个循环下载什么的，这样似乎可以方便的扒很多图片的赶脚。


-m 10 -o /dev/null -s -w %{http_code}



 -I 仅测试HTTP头

 -m 10 最多查询10s

 -o /dev/null 屏蔽原有输出信息

 -s silent

 -w %{http_code} 控制额外输出
