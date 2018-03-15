# Blockchain Inspector proof of concept.

Run it with docker-compose up -d.

## blockchain2graph.
This docker image contains [neo4j](https://neo4j.com) & [blockchain2graph](https://github.com/straumat/blockchain2graph). 

Once started you can access Blockchain2graph console at [http://localhost:8080](http://localhost:8080) and Neo4j console at [http://localhost:7474/browser](http://localhost:7474/browser).  

## bci-ai-runner.
This docker image take as parameter the rule you want to apply. Once you run it, it will apply the rules to the data in neo4j.

You can follow the results by connecting to the Neo4j console at [http://localhost:7474/browser](http://localhost:7474/browser).


It connects to our bitcoind service and imports 



# Blockchain Inspector proof of concept.
Docker images for Blockchain Inspector proof of concept.

There are two ways to test : 
* Work with test data (load only 100 000 blocks in neo4j) : ``. 
* Test with more data (run bitcoind and blockchain import): ``.

## Bitcoind.
`bitcoind` service will start a bitcoind node with no data. The data retrieved will be stored in `bitcoind/data/`.
u 
## Neo4j.
`neo4j` service will start a neo4j server with 100 000 blocks already imported.

You can see and query the data in neo4j with the administration tool running at [http://localhost:7474/](http://localhost:7474/).

## Blockchain2graph.
`blockchain2graph` will start [Blockchain2Graph](https://github.com/straumat/blockchain2graph), a tool that will import blocks from `bitcoind` into `neo4j`.

You can see the console at [http://localhost:8080/blockchain2graph/](http://localhost:8080/blockchain2graph/).

## Blockchain Inspector.
`blockchain-inspector` executes rules stored in `blockchain-inspector/src`.