# Main Entry Point: Receives joystick data, determines controller type, routes to appropriate handler
# Primary callback for /joy topic. Checks joystick data validity, triggers arm state query
# if needed, detects controller type by button count (15=Jetson, else=PC), and routes to
# appropriate handler function for button/axis processing.
def buttonCallback(self, joy_data):
    #self.get_logger().info(f"buttonCallback called! Buttons: {len(joy_data.buttons)}, Axes: {len(joy_data.axes)}")
    #self.get_logger().info(f"Buttons : {joy_data.buttons}")
    if not isinstance(joy_data, Joy): return
    
    # Check if arm synchronization is needed
    if self.getArm_active: 
        self.srv_armcallback()
    elif not self.arm_synchronized and self.sync_attempts < self.max_sync_attempts:
        self.sync_attempts += 1
        self.get_logger().info(f"Retrying arm synchronization (attempt {self.sync_attempts}/{self.max_sync_attempts})")
        self.srv_armcallback()
    
    # Route to appropriate controller handler (robot movement should always work)
    if len(joy_data.buttons) == 15: 
        self.user_jetson(joy_data)
    else: 
        self.user_pc(joy_data) 