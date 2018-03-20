# Blockchain Inspector proof of concept.

## What is Blockchain Inspector ?

## How does it works ?

## How to run it ?

The first step is to start the environment and you have three choices : 
  * Test with our provided data set (100 000 blocks imported) : run `docker-compose up -d`.
  * Test while continuing to import blocks from our public bitcoind server : run `docker-compose -f docker-compose-with-b2g-and-public-bitcoind.yml up -d`.
  * Test while continuing to import blocks from your private bitcoind server : run `docker-compose -f docker-compose-with-b2g-and-private-bitcoind.yml up -d`.

_The first choice starts only one container (neo4j), the second choice starts two containers (neo4j & blockchain2graph) and the third choice starts three containers (neo4j, blockchain2graph & bitcoind)._

In all cases, you wan see the data by connecting to the ne4j console at [http://localhost:7474/browser/](http://localhost:7474/browser/) with `neo4j` as login and `neo4j123` as password.
 
The second step is to select or create the use case you want to run : 
  * Use case 1 : IF an address (A) makes regular money transfer to another address B owned by an entity that is a restaurant THEN A's owner address country = B's owner address.
  * Use case 2 : IF an address (A) makes a money transfer to a IRAN THEN Raises an alert.
  * Use case 3 : IF a bitcoin address makes a transaction to a well known foundation (like wikipedia) THEN create a relationship "made a donation" to the foundation.
  * Use case 4 : I recently join an association by making a payment to the address : 1MusC4FBPxwVGY1xADBouMRfybVwJvUM9v. If an address also make a payment to this address, then the owner is a member of the association (90%).
  * Use case 5 : IF a known bitcoin address receives money from an address used by ransomeware THEN raise an alert.
  * Use case 6 : IF a payment is made to this distributor located in France THEN the country of the owner is France (25% sure).
  * Use case 7 : IF a known enterprise make payment between 1 000<80> & 4 000 <80> every month to an address THEN the owner is probably (80%) working for this company.

To run a case, the source must be in the `src` folder and you just have to run : `docker  run -it -v /opt/workspace/bci-ai-runner/src:/src -e $SRC_FILE="hello.cc" bci-ai-runner`

You can then see the result of the execution by connection to neo4j console :
  * Use case 1 : CYPHER_QUERY
  * Use case 2 : CYPHER_QUERY
  * Use case 3 : CYPHER_QUERY
  * Use case 4 : CYPHER_QUERY
  * Use case 5 : CYPHER_QUERY
  * Use case 6 : CYPHER_QUERY
  * Use case 7 : CYPHER_QUERY
  
You can also create your own rule in the `src` folder and execute them.

## Containers description.

### bitcoind.

### neo4j.

### blockchain2graph.

### bci-ai-runner.





This docker image contains [neo4j](https://neo4j.com) & [blockchain2graph](https://github.com/straumat/blockchain2graph). 

Once started you can access Blockchain2graph console at [http://localhost:8080](http://localhost:8080) and Neo4j console at [http://localhost:7474/browser](http://localhost:7474/browser).  

## bci-ai-runner.
This docker image take as parameter the rule you want to apply. Once you run it, it will apply the rules to the data in neo4j.

You can follow the results by connecting to the Neo4j console at [http://localhost:7474/browser](http://localhost:7474/browser).


It connects to our bitcoind service and imports.
