# Blockchain Inspector proof of concept.

## What is Blockchain Inspector ?
Thanks to our own ten-year-old Artificial Intelligence engine, we allow you to profile Bitcoin users. The key advantage of our solution is that it can easily translates human reasoning into rules and in so doing can transpose the experience of experts into a computer system capable of processing very large amounts of data.

## How does it work ?
You can read a complete description of our product and our POC on our website : [http://blockchaininspector.com](http://blockchaininspector.com).

## How to run it ?
First, you need to install git and docker. On Ubuntu/Debian, just run this command `sudo apt-get install docker.io docker-compose git`.

Download the code at [https://github.com/straumat/bci-poc](https://github.com/straumat/bci-poc) or retrieve it using this git command : `git clone https://github.com/straumat/bci-poc.git`.

The first step is to start the environment and you have three choices : 
  * Test with our provided data set (70 000 blocks imported) : run `sudo docker-compose up`.
  * Test while continuing to import blocks from our public bitcoin core server : run `sudo docker-compose -f docker-compose-with-b2g-and-public-bitcoind.yml up`.
  * Test while continuing to import blocks from your private bitcoin core server : run `sudo docker-compose -f docker-compose-with-b2g-and-private-bitcoind.yml up`.

_The first choice starts only one container (neo4j), the second choice starts two containers (neo4j & blockchain2graph) and the third choice starts three containers (neo4j, blockchain2graph & bitcoind)._

In all cases, you wan see the data by connecting to the ne4j console at [http://localhost:7474/browser/](http://localhost:7474/browser/) with `neo4j` as login and `b2g135!` as password.

The second step is to select or create the rule you want to run : 
  * Rule 1 : IF an address (A) makes regular money transfer to another address B owned by an entity that is a restaurant THEN A's owner address country = B's owner address.
  * Rule 2 : IF an address (A) makes a money transfer to a IRAN THEN Raises an alert.
  * Rule 3 : IF a bitcoin address makes a transaction to a well known foundation (like wikipedia) THEN create a relationship "made a donation" to the foundation.
  * Rule 4 : I recently join an association by making a payment to the address : 1MusC4FBPxwVGY1xADBouMRfybVwJvUM9v. If an address also make a payment to this address, then the owner is a member of the association (90%).
  * Rule 5 : IF a known bitcoin address receives money from an address used by ransomeware THEN raise an alert.
  * Rule 6 : IF a payment is made to this distributor located in France THEN the country of the owner is France (25% sure).
  * Rule 7 : IF a known enterprise make payment between 1 000<80> & 4 000 <80> every month to an address THEN the owner is probably (80%) working for this company.

To run a case, you just have to run : `sudo docker run -it -v /PATH/bci-poc/src:/src --net=host -e RULE=1 straumat/bci-ai-runner:1.0`

Replace `PATH` by the path to the bci-poc project `src` directory and `1` by the rule number you want to execute.

You can also create your own rule in the `src` folder and execute them. 