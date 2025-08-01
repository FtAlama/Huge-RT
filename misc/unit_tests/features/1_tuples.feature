Feature:tuples are being created
	
	Scenario: A tuple with w=1.0 is a point
		Given a = tuple(4.3, -4.2, 3.1, 1.0)
		Then a.x == 4.3
		And a.y == -4.2
		And a.z == 3.1
		And a.w == 1.0
		And a is a point
		And a is not a vector		

	Scenario: A tuple with w=0 is a vector
		Given a = tuple(4.3, -4.2, 3.1, 0)
		Then a.x == 4.3
		And a.y == -4.2
		And a.z == 3.1
		And a.w == 0
		And a is not a point
		And a is a vector		

	Scenario: create_point() creates tuples with w=1.0
		Given p = create_point(4, -4, 3)
		Then p == tuple(4, -4, 3, 1)

	Scenario: create_vector() creates tuples with w=0
		Given v = create_vector(4, -4, 3)
		Then v == tuple(4, -4, 3, 0)
