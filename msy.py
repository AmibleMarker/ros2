#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class msy(Node):
   
    def __init__(self,name):
        super().__init__(name)
        

        self.money = self.create_publisher(String,"rmb", 10) 
 	
        self.i = 0 
        timer_period = 5  
        self.timer = self.create_timer(timer_period, self.timer_callback) 


    def timer_callback(self):
        """
        定时器回调函数
        """
        msg = String()
        msg.data = '第%d次：发送 %d 次' % (self.i,self.i)
        self.money.publish(msg)  
        self.get_logger().info('我发布了：%s' % msg.data)    
        self.i += 1 

def main(args=None):
    
    rclpy.init(args=args) 
    node = msy("msy")  
    rclpy.spin(node) 
    rclpy.shutdown() 

