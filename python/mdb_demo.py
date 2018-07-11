import MySQLdb as mdb

conn = mdb.connect(user="root", passwd="admin@123", db="students")
c = conn.cursor()

#################Read operation on db start####################
c.execute("select * from employees")
print( c.fetchall())
################Read operation on db end######################

#################Update operation on db start#################
c.execute('update employees set designation="senior software engineer" where eid="VT9452"')
conn.commit()
#################Update operation on db end##################

################Delete operation on db start################
c.execute('delete from employees where eid="VT3214"')
conn.commit()
################Delete operation on db end##################

################INsert operation on db start##############
c.execute('insert into employees(eid, name, designation, exp)values("VT9870", "shanti", "trainee", 1)')
conn.commit()
###############INsert operation on db end#################


