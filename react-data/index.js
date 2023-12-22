const path = require('path')
const fs = require('fs')

const csv=require('csvtojson')
const csvFilePath = path.join(__dirname, "data/kajran_csv.csv")

csv().fromFile(csvFilePath).then((json)=>{
    fs.writeFile("../react-admin-dashboard/src/data/outputjson.json", JSON.stringify(json),"utf-8", (err)=>{if (err) console.log(err)})
})

