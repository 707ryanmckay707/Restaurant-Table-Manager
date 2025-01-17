// Created by Luke Shoulders and Nicole Taketa
// Updated by Ryan McKay
// - Added restid param to Tables route

const TableController = require('../controllers/tableController.js');

const tableController = new(require('../controllers/tableController.js'))();

const tableRouter = require('koa-router')({
    prefix: '/table'
});

tableRouter.get('/:restid', tableController.tables); // Created by Luke Shoulders, updated by Ryan McKay

// TODO: Test the functionality of this route, it adds a new table
//       with an insert statement to the `table` table in the database.
tableRouter.get('/:id/:nbr/:status', tableController.addTable, tableController.tables); // Created by Luke Shoulders

// Sets the status of all tables in the given restaurant to open
// Unused currently in the program as far as I am aware
// Bug?: Does not remove a party that is seated at the table
//       (This bug/requirement may be fixed/covered by another route 
//       depending on how it is implemented in the Qt code)
tableRouter.get('/:id/open', tableController.openTables); // Created by Luke Shoulders

// As a route, seems to work correctly at a basic level
// Is currently unused/integrated
tableRouter.get('/:id/:nbr/:status/updatestatus', tableController.updateTableStatus); // Created by Nicole Taketa



module.exports = tableRouter;
