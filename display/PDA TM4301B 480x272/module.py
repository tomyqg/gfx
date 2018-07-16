def loadModule():
	component = Module.CreateComponent("gfx_disp_pdatm4301b_480x272", "PDA TM4301B", "/Graphics/Displays/", "tm4301b.py")
	component.setDisplayType("480x272 PCAP Display")
	component.addCapability("gfx_display", "Graphics Display", False)
	component.addCapability("touch_panel", "Touch Panel", False)