import { Keypair } from "@solana/web3.js"

const keypair = Keypair.generate();

console.log("Public Key:", keypair.publicKey.toString());
console.log("Private Key:", keypair.secretKey.toString());
console.log("Sucessfully generated");