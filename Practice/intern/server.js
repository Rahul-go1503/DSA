const express = require('express')
const mongoose = require('mongoose')
const app = express()

const urlSchema= new mongoose.Schema({
    url:{
        type: String
    },
    hash: String
})

const urlmodal= mongoose.model('url',urlSchema);

app.use(express.json());
app.use(cors());
// app.use(function(req, res, next) {
//     res.header("Access-Control-Allow-Origin", "*"); // update to match the domain you will make the request from
//     res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
//     next();
//   });
const dbURI ='mongodb://localhost:27017/ShortUrl';

mongoose.connect(dbURI).then(
    console.log('connected to databse successfully')
)
app.post('/addurl', async(req,res)=>{
    try{
        const urlentry= await urlmodal.create({
            url: req.body.data.url,
            hash: req.body.data.hash
        })
        urlentry.save();
        res.send(urlentry);
        
    }catch(err){
        console.log(err);
    }
})
app.get('/:hash',async (req,res)=>{
    // console.log(req.params.hash);
    // console.log(typeof req.params.hash);
    try{
        const urlentry= await urlmodal.find({hash : String(req.params.hash)});
        if(!urlentry){
            console.log('url not found');
            res.send({'success':false});
        }
        console.log(urlentry)
        res.send(urlentry);

    }catch(err){
        console.log(err);
    }
})
app.listen(4000,()=>{
    console.log('app is listening to the port 4000')
})

