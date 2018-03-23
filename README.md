# Blockchain Inspector proof of concept.

## What is Blockchain Inspector ?

## How does it works ?

## How to run it ?

Download the code at [https://github.com/straumat/bci-poc](https://github.com/straumat/bci-poc). The easiest way to do it is to use git command : `git clone https://github.com/straumat/bci-poc.git̀`.

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

To run a case, the source must be in the `src` folder and you just have to run : `docker run -it -v /opt/workspace/bci-poc/src:/src -e SRC_FILE="helloWorld/hello.cc" straumat/bci-ai-runner:1.0`

You can then see the result of the execution by connection to neo4j console :
  * Use case 1.
    * Run it : 
    * View results : 
  * Use case 2.
    * Run it : 
    * View results : 
  * Use case 3.
    * Run it : 
    * View results : 
  * Use case 4.
    * Run it : 
    * View results : 
  * Use case 5.
    * Run it : 
    * View results : 
  * Use case 6.
    * Run it : 
    * View results : 
  * Use case 7.
    * Run it : 
    * View results : 

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
