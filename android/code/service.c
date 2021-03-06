
service

不是一个单独的进程
不是一个线程

创建一个类，继承servce; 复写onCreate onDestroy onStartCommand等
在AndroidManifest.xml注册

启动服务
   Intent intent
   intent.setClass();
   startService(intent);

关闭服务
   Intent intent
   intent.setClass();
   stopService(intent);

onStartCommand 接收intent对象的数据，实现service的主功能
    
返回值：
  START_STICKY：如果service进程被kill掉，保留service的状态为开始状态，但不保留递送的intent对象。
随后系统会尝试重新创建service，由于服务状态为开始状态，所以创建服务后一定会调用
onStartCommand(Intent,int,int)方法。如果在此期间没有任何启动命令被传递到service，那么参数Intent将为null。

 START_NOT_STICKY：“非粘性的”。使用这个返回值时，如果在执行完onStartCommand后，服务被异常kill掉，系统不会自动重启该服务。

 START_REDELIVER_INTENT：重传Intent。使用这个返回值时，如果在执行完onStartCommand后，
服务被异常kill掉，系统会自动重启该服务，并将Intent的值传入。

 START_STICKY_COMPATIBILITY：START_STICKY的兼容版本，但不保证服务被kill后一定能重启。

