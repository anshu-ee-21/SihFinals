import { Box } from "@mui/material";
import { DataGrid, GridToolbar } from "@mui/x-data-grid";
import { tokens } from "../../theme";
import jsonData from '../../data/outputjson.json'
import Header from "../../components/Header";
import { useTheme } from "@mui/material";

const DataPage = () => {
  const theme = useTheme();
  const colors = tokens(theme.palette.mode);
  console.log(jsonData)

  const columns = [
    { field: "time", headerName: "Time(in seconds)", flex: 1 },
    { field: "inflow", headerName: "Inflow(in cc/sec)" },
    {
      field: "waterlevel",
      headerName: "Water Level(in cm)",
      flex: 1,
    },
    {
      field: "percentageopen",
      headerName: "Opening of Gates(%)",
      type: "number",
      headerAlign: "left",
      align: "left",
      flex:1
    },
    {
      field: "alertlevel",
      headerName: "Alert Level(in cm)",
      flex: 1,
    },
    {
      field: "outflow",
      headerName: "Outflow(in cc/sec)",
      flex: 1,
    },
  ];

  return (
    <Box m="20px">
      <Header
        title="DAM DATA"
        // subtitle="List of Contacts for Future Reference"
      />
      <Box
        m="40px 0 0 0"
        height="75vh"
        sx={{
          "& .MuiDataGrid-root": {
            border: "none",
          },
          "& .MuiDataGrid-cell": {
            borderBottom: "none",
          },
          "& .name-column--cell": {
            color: colors.greenAccent[300],
          },
          "& .MuiDataGrid-columnHeaders": {
            backgroundColor: colors.blueAccent[700],
            borderBottom: "none",
          },
          "& .MuiDataGrid-virtualScroller": {
            backgroundColor: colors.primary[400],
          },
          "& .MuiDataGrid-footerContainer": {
            borderTop: "none",
            backgroundColor: colors.blueAccent[700],
          },
          "& .MuiCheckbox-root": {
            color: `${colors.greenAccent[200]} !important`,
          },
          "& .MuiDataGrid-toolbarContainer .MuiButton-text": {
            color: `${colors.grey[100]} !important`,
          },
        }}
      >
        <DataGrid
          rows={jsonData}
          columns={columns}
          components={{ Toolbar: GridToolbar }}
        />
      </Box>
    </Box>
  );
};

export default DataPage;
