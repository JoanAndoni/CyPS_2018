import com.mongodb.*;

MongoClient cli = new MongoClient("localhost", 27017);
DB mydb  = cli.getDB("test");

DBCollection nombres  = mydb.getCollection("nombres");

//BasicDBList

//Insertar un documento
BasicDBObject bdbo = new BasicDBObject();
bdbo.append("nombre", "Julio");
WriteResult writer = nombres.insert(bdbo, WriteConcern.ACKNOWLEDGED);
if(writer.wasAcknowledged())
  OUT.println("Se escribió el objeto en la base de datos");
else
  OUT.println("NO Se escribió el objeto en la base de datos");
SampleResult.setResponseData(writer.toString().getBytes());

//Insertar un arreglo de documentos
bdbo = new BasicDBObject();
bdbo.append("nombre","Rosita");
BasicDBList bdbl = new BasicDBList();
bdbl.add("5454545");
bdbl.add("3423545");
bdbl.add("2343544");
bdbo.append("telefonos", bdbl);
writer = nombres.insert(bdbo, WriteConcern.ACKNOWLEDGED);
SampleResult.setResponseData(writer.toString().getBytes());

//DBObject
BasicDBObject busqueda = new BasicDBObject("nombre", "Julio");
DBCursor dbo = nombres.find(busqueda);
StringBuilder s = new StringBuilder();
while(dbo.hasNext())
{
  DBObject res = dbo.next();
  println(res.toString());
}

vars.put("resultado", s.toString());
